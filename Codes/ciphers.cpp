#include "ciphers.h"
#include <iostream>
#include <fstream>
#include <cctype>

using std::cout, std::cin, std::ifstream, std::cerr, std::endl, std::ofstream;

void decryptFile(const string& filename) {
    int choice = printMenu("decrypt");

    if (choice == 1) {
        int numberToShift;
        cout << "How many to shift? ";
        cin >> numberToShift;

        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error opening file." << endl;
            return;
        }

        string line;
        string decryptedContents;

        while (getline(inputFile, line)) {
            decryptedContents += shiftLetters(line, numberToShift, false) + "\n";
        }

        inputFile.close();

        ofstream outputFile(filename);
        if (!outputFile) {
            cerr << "Couldn't open file.";
            return;
        }

        outputFile << decryptedContents;
        outputFile.close();
    }
}

void encryptFile(const string& filename) {
    int choice = printMenu("encrypt");

    if (choice == 1) {
        int numberToShift;
        cout << "How many to shift? ";
        cin >> numberToShift;

        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error opening file." << endl;
            return;
        }

        string line;
        string encryptedContents;

        while (getline(inputFile, line)) {
            encryptedContents += shiftLetters(line, numberToShift, true) + "\n";
        }

        inputFile.close();

        ofstream outputFile(filename);
        if (!outputFile) {
            cerr << "Couldn't open file.";
            return;
        }

        outputFile << encryptedContents;
        outputFile.close();
    }
}

string shiftLetters(const string& input, int shiftAmount, bool encrypt) {
    string result = input;

    for (char& c : result) {
        if (isalpha(c)) {
            c = tolower(c);
            if (encrypt) {
                c += shiftAmount;
                c = 'a' + (c - 'a') % 26;
            }
            else {
                c = 'z' - ('z' - c + shiftAmount) % 26;
            }
        }
    }

    return result;
}