#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>

class GroceryTracker {
private:
    std::map<std::string, int> itemFrequency;
    std::string inputFile;
    std::string outputFile;

    void LoadData();
    void SaveData();

public:
    GroceryTracker(const std::string& inputFile, const std::string& outputFile);
    void GetItemFrequency();
    void PrintAllFrequencies();
    void PrintHistogram();
};

#endif // GROCERYTRACKER_H
