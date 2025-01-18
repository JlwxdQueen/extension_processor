#include <iostream>

#include "../include/processor.hpp"
#include "generator/gitattributes_generator.hpp"

int main() {
    std::string input;
    std::cout << "Input the string in format: path_to_file1;path_to_file2;path_to_file3; ..." << std::endl;
    std::getline(std::cin, input);

    Processor processor(input);
    processor.process();

    const std::unordered_set fileExtensions(processor.getFileExtensions().begin(), processor.getFileExtensions().end());

    generateGitattributes(fileExtensions);
    return 0;
}
