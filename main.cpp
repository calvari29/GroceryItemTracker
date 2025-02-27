#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <string>

class GroceryTracker {
private:
    std::map<std::string, int> itemFrequency;
    std::string inputFile = "CS210_Project_Three_Input_File.txt";
    std::string outputFile = "frequency.dat";

    void LoadData() {
        std::ifstream file(inputFile);
        std::string item;
        if (file.is_open()) {
            while (file >> item) {
                itemFrequency[item]++;
            }
            file.close();
            SaveData();
        }
        else {
            std::cerr << "Error: Unable to open input file!" << std::endl;
        }
    }

    void SaveData() {
        std::ofstream outFile(outputFile);
        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << std::endl;
        }
        outFile.close();
    }

public:
    GroceryTracker() {
        LoadData();
    }

    void GetItemFrequency() {
        std::string item;
        std::cout << "Enter item name: ";
        std::cin >> item;
        if (itemFrequency.find(item) != itemFrequency.end()) {
            std::cout << item << " appears " << itemFrequency[item] << " times." << std::endl;
        }
        else {
            std::cout << "Item not found in records." << std::endl;
        }
    }

    void PrintAllFrequencies() {
        std::cout << "\nGrocery Item Frequencies:\n";
        for (const auto& pair : itemFrequency) {
            std::cout << pair.first << " " << pair.second << std::endl;
        }
    }

    void PrintHistogram() {
        std::cout << "\nGrocery Item Histogram:\n";
        for (const auto& pair : itemFrequency) {
            std::cout << std::setw(12) << std::left << pair.first << " ";
            for (int i = 0; i < pair.second; i++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
};

void DisplayMenu() {
    std::cout << "\nGrocery Item Tracker Menu:\n";
    std::cout << "1. Search for an item frequency\n";
    std::cout << "2. Print all item frequencies\n";
    std::cout << "3. Print histogram\n";
    std::cout << "4. Exit\n";
}

int main() {
    GroceryTracker tracker;
    int choice;

    do {
        DisplayMenu();
        std::cout << "Enter your choice: ";
        while (!(std::cin >> choice) || choice < 1 || choice > 4) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 4: ";
        }

        switch (choice) {
        case 1:
            tracker.GetItemFrequency();
            break;
        case 2:
            tracker.PrintAllFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            std::cout << "Exiting program...\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
