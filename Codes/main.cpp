#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void decryptFile(const string& filename);
void encryptFile(const string& filename);
int printMenu(string operation);
string shiftLetters(const string& input, int shiftAmount);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Syntax: " << argv[0] << " -d|decrypt -e|encrypt [file]" << endl;
        return 1;
    }

    string operation = argv[1];
    string filename = argv[2];

    if (operation == "encrypt" || operation == "-e") {
        encryptFile(filename);
    }
    else if (operation == "decrypt" || operation == "-d") {
        decryptFile(filename);
    }
    else {
        cerr << "No valid operation chosen." << endl;
        return 1;
    }
}

int printMenu(string operation) {
    if (operation == "encrypt" || operation == "-e") {
        cout << "Choose encryption technique:" << endl << endl <<
            "1. Caesar shift" << endl;
    }

    int choice;
    cin >> choice;
    return choice;
}

string shiftLetters(const string& input, int shiftAmount) {
    string result = input;

    for (char& c : result) {
        if (isalpha(c)) {
            c = tolower(c);
            c += shiftAmount;
            c = 'a' + (c - 'a') % 26;
        }
    }

    return result;
}

void decryptFile(const string& filename) {
    // decryption logic goes here
}

void encryptFile(const string& filename) {
    int choice = printMenu("encrypt");

    if (choice == 1) {
        int numberToShift;
        cout << "How many to shift? ";
        cin >> numberToShift;

        string contents;
        ifstream inputFile(filename);
        if (!inputFile) {
            cerr << "Error opening file." << endl;
            return;
        }

        string line;
        while (getline(inputFile, line)) {
            contents += line + "\n";
        }

        inputFile.close();

        cout << endl << "Contents: " << contents << endl;
        cout << "Encrypted: " << shiftLetters(contents, numberToShift);
    }
}