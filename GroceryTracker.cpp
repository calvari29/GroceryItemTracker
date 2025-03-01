#include "GroceryTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

GroceryTracker::GroceryTracker(const std::string& inputFile, const std::string& outputFile)
    : inputFile(inputFile), outputFile(outputFile) {
    LoadData();
}

void GroceryTracker::LoadData() {
    std::ifstream file(inputFile);
    std::string item;
    if (file.is_open()) {
        while (file >> item) {
            itemFrequency[item]++;
        }
        file.close();
        SaveData();
    } else {
        std::cerr << "Error: Unable to open input file: " << inputFile << std::endl;
    }
}

void GroceryTracker::SaveData() {
    std::ofstream outFile(outputFile);
    if (outFile.is_open()) {
        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << std::endl;
        }
        outFile.close();
    } else {
        std::cerr << "Error: Unable to open output file: " << outputFile << std::endl;
    }
}

void GroceryTracker::GetItemFrequency() {
    std::string item;
    std::cout << "Enter item name: ";
    std::cin >> item;
    if (itemFrequency.find(item) != itemFrequency.end()) {
        std::cout << item << " appears " << itemFrequency[item] << " times." << std::endl;
    } else {
        std::cout << "Item not found in records." << std::endl;
    }
}

void GroceryTracker::PrintAllFrequencies() {
    std::cout << "\nGrocery Item Frequencies:\n";
    for (const auto& pair : itemFrequency) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
}

void GroceryTracker::PrintHistogram() {
    std::cout << "\nGrocery Item Histogram:\n";
    for (const auto& pair : itemFrequency) {
        std::cout << std::setw(12) << std::left << pair.first << " ";
        for (int i = 0; i < pair.second; i++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
