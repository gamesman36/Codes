#include <iostream>
#include <string>

using namespace std;

void decryptFile(const string& filename);
void encryptFile(const string& filename);

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

void decryptFile(const string& filename) {
	// decryption logic goes here
}

void encryptFile(const string& filename) {
	// encryption logic goes here
}