#include "cleaner.h"
#include <algorithm>
#include <set>
#include <sstream>
#include <cctype>
#include <regex>

// Trim spaces from start and end
std::string Cleaner::trim(const std::string &str) {
    size_t start = str.find_first_not_of(" ");
    size_t end = str.find_last_not_of(" ");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

// Convert text to lowercase
std::string Cleaner::toLower(const std::string &str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Remove extra spaces between words
std::string Cleaner::removeExtraSpaces(const std::string &str) {
    std::string result;
    bool space = false;

    for (char c : str) {
        if (isspace(c)) {
            if (!space) {
                result += ' ';
                space = true;
            }
        } else {
            result += c;
            space = false;
        }
    }
    return trim(result);
}

// Normalize punctuation (IMPORTANT FIX)
std::string normalizePunctuation(const std::string &text) {
    std::string result = text;

    // Remove spaces before punctuation (e.g. "hello !" → "hello!")
    result = std::regex_replace(result, std::regex("\\s+([!?.])"), "$1");

    // Convert multiple ! → single !
    result = std::regex_replace(result, std::regex("!+"), "!");

    // Convert multiple ? → single ?
    result = std::regex_replace(result, std::regex("\\?+"), "?");

    // Convert multiple . → single .
    result = std::regex_replace(result, std::regex("\\.+"), ".");

    return result;
}

// Remove duplicate lines
std::vector<std::string> Cleaner::removeDuplicates(const std::vector<std::string> &data) {
    std::set<std::string> seen;
    std::vector<std::string> result;

    for (auto &line : data) {
        if (seen.insert(line).second) {
            result.push_back(line);
        }
    }
    return result;
}

// Main cleaning function
std::string Cleaner::cleanText(const std::string &text) {
    std::string cleaned = trim(text);
    cleaned = toLower(cleaned);
    cleaned = removeExtraSpaces(cleaned);
    cleaned = normalizePunctuation(cleaned);

    return cleaned;
}