#include <iostream>
#include "file_handler.h"

int main() {
    std::cout << "Choose file type:\n";
    std::cout << "1. CSV\n2. JSON\n";
    
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        cleanCSV("Data/input.csv", "Data/output.csv");
        std::cout << "CSV cleaned successfully!\n";
    }
    else if (choice == 2) {
        cleanJSON("Data/input.json", "Data/output.json");
        std::cout << "JSON cleaned successfully!\n";
    }
    else {
        std::cout << "Invalid choice\n";
    }

    return 0;
}