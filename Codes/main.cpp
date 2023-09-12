#include <iostream>
#include "ciphers.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "Syntax: " << argv[0] << "(e)ncrypt|(d)ecrypt [file]" << endl;
		return 1;

		if (argv[1] == "encrypt" || argv[1] == "e") encryptFile(argv[2]);
		else if (argv[1] == "decrypt" || argv[1] == "d") decryptFile(argv[2]);
		else {
			cerr << "No valid operation chosen." << endl;
			return 1;
		}
	}
}