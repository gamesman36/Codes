#pragma once

#include <string>

using std::string;

int printMenu(string operation);

void decryptFile(const string& filename);
void encryptFile(const string& filename);
string shiftLetters(const string& input, int shiftAmount, bool encrypt);