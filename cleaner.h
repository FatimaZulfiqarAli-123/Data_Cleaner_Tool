#ifndef CLEANER_H
#define CLEANER_H

#include <string>
#include <vector>

class Cleaner {
public:
    std::string trim(const std::string &str);
    std::string toLower(const std::string &str);
    std::string removeExtraSpaces(const std::string &str);
    std::vector<std::string> removeDuplicates(const std::vector<std::string> &data);
    std::string cleanText(const std::string &text);
};

#endif