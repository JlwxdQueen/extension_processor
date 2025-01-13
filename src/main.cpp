#include <iostream>
#include <string>
#include "../include/processor.h"

int main() {
    const std::string input = "dir1/file1.txt;LICENSE;.gitignore;dir2/file2.jpg;README;dir3/subdir/.hiddenfile;";
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
