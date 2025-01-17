#include <iostream>
#include <string>
#include "../include/processor.h"

int main() {
    std::string input;

    std::cout << "Input the string in format: path_to_file1;path_to_file2;path_to_file3; ... ;" << std::endl;

    std::getline(std::cin, input);
    Processor processor(input);
    processor.process();

    std::cout << "File Names:" << std::endl;
    for (const auto &name: processor.getFileNames()) {
        std::cout << " - " << name << '\n';
    }

    std::cout << "File Extensions:" << std::endl;
    for (const auto &ext: processor.getFileExtensions()) {
        std::cout << " - " << ext << '\n';
    }

    return 0;
}
