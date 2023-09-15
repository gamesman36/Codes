#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void decryptFile(const string& filename);
void encryptFile(const string& filename);
int printMenu(string operation);
string shiftLetters(const string& input, int shiftAmount, bool encrypt);

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

    else if (operation == "decrypt" || operation == "-d") {
        cout << "Choose cipher to decrypt:" << endl << endl <<
            "1. Caesar shift" << endl;
    }

    int choice;
    cin >> choice;
    return choice;
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