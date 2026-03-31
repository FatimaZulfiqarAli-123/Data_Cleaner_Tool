#include "file_handler.h"
#include "cleaner.h"
#include <fstream>
#include <sstream>
#include <vector>

// -------- CSV CLEANER --------
void cleanCSV(const std::string &inputPath, const std::string &outputPath) {
    Cleaner cleaner;
    std::ifstream inFile(inputPath);
    std::ofstream outFile(outputPath);

    std::string line;

    while (getline(inFile, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> cleanedRow;

        while (getline(ss, cell, ',')) {
            cleanedRow.push_back(cleaner.cleanText(cell));
        }

        for (size_t i = 0; i < cleanedRow.size(); i++) {
            outFile << cleanedRow[i];
            if (i != cleanedRow.size() - 1)
                outFile << ",";
        }
        outFile << "\n";
    }
}

// -------- JSON CLEANER (simple version) --------
void cleanJSON(const std::string &inputPath, const std::string &outputPath) {
    Cleaner cleaner;
    std::ifstream inFile(inputPath);
    std::ofstream outFile(outputPath);

    std::string line;

    while (getline(inFile, line)) {
        outFile << cleaner.cleanText(line) << "\n";
    }
}