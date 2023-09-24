#include "ciphers.h"
#include <iostream>

using std::string, std::cin, std::cout, std::cerr, std::endl, std::ifstream, std::ofstream;

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