#include "ciphers.h"
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;

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