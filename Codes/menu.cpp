#include "menu.h"
#include <iostream>

int printMenu(std::string operation) {
    if (operation == "encrypt" || operation == "-e") {
        std::cout << "Choose encryption technique:" << std::endl << std::endl <<
            "1. Caesar shift" << std::endl;
    }
    else if (operation == "decrypt" || operation == "-d") {
        std::cout << "Choose cipher to decrypt:" << std::endl << std::endl <<
            "1. Caesar shift" << std::endl;
    }

    int choice;
    std::cin >> choice;
    return choice;
}