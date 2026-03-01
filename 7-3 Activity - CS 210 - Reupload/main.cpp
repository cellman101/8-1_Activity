/*
 * Corner Grocer Item-Tracking Program (Case-Insensitive Version)
 * Developer: Ty Yahraus
 * Date: February 2026
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <limits>
#include <algorithm>

using namespace std;

// Helper function to convert string to lowercase
string ToLower(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(),
        [](unsigned char c) { return tolower(c); });
    return lower;
}

class GroceryTracker {
public:
    bool LoadInputFile(const string& inputFilename) {
        ifstream inFile(inputFilename);
        if (!inFile.is_open()) {
            return false;
        }

        m_frequencies.clear();
        string item;

        while (inFile >> item) {
            item = ToLower(item);  // Convert to lowercase
            ++m_frequencies[item];
        }

        inFile.close();
        return true;
    }

    bool WriteFrequencyFile(const string& outputFilename) const {
        ofstream outFile(outputFilename);
        if (!outFile.is_open()) {
            return false;
        }

        for (const auto& pair : m_frequencies) {
            outFile << pair.first << " " << pair.second << "\n";
        }

        outFile.close();
        return true;
    }

    int GetItemFrequency(const string& item) const {
        string lowerItem = ToLower(item); // Normalize user input
        auto it = m_frequencies.find(lowerItem);
        if (it == m_frequencies.end()) {
            return 0;
        }
        return it->second;
    }

    void PrintAllFrequencies() const {
        for (const auto& pair : m_frequencies) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    void PrintHistogram(char symbol = '*') const {
        for (const auto& pair : m_frequencies) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << symbol;
            }
            cout << endl;
        }
    }

private:
    map<string, int> m_frequencies;
};

void PrintMenu() {
    cout << "\n===== Corner Grocer Menu =====\n";
    cout << "1. Look up an item frequency\n";
    cout << "2. Print all item frequencies\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int GetMenuChoice() {
    int choice;

    while (true) {
        cin >> choice;

        if (!cin.fail() && choice >= 1 && choice <= 4) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid choice. Enter 1–4: ";
    }
}

string GetItemFromUser() {
    cout << "Enter the item to look for: ";
    string item;
    getline(cin, item);
    return item;
}

int main() {
    const string inputFileName = "CS210_Project_Three_Input_File.txt";
    const string outputFileName = "frequency.dat";

    GroceryTracker tracker;

    if (!tracker.LoadInputFile(inputFileName)) {
        cout << "Error: Could not open input file.\n";
        return 1;
    }

    if (!tracker.WriteFrequencyFile(outputFileName)) {
        cout << "Error: Could not create frequency.dat\n";
        return 1;
    }

    bool running = true;

    while (running) {
        PrintMenu();
        int choice = GetMenuChoice();

        switch (choice) {
        case 1: {
            string item = GetItemFromUser();
            cout << item << " "
                 << tracker.GetItemFrequency(item) << endl;
            break;
        }
        case 2:
            tracker.PrintAllFrequencies();
            break;

        case 3:
            tracker.PrintHistogram('*');
            break;

        case 4:
            running = false;
            cout << "Program Finished.\n";
            break;
        }
    }

    return 0;
}