#include <utility>

#include "../include/processor.hpp"

Processor::Processor(std::string input) : input(std::move(input)) {}

void Processor::process() {
    extractFileNames();
    extractFileExtensions();
}

const std::set<std::string> &Processor::getFileExtensions() const { return fileExtensions; }

const std::vector<std::string> &Processor::getFileNames() const { return fileNames; }

void Processor::extractFileNames() {
    size_t start = 0, end;
    while ((end = input.find(';', start)) != std::string::npos) {
        std::string token = input.substr(start, end - start);
        size_t lastSlash = token.find_last_of('/');
        if (lastSlash != std::string::npos) {
            fileNames.push_back(token.substr(lastSlash + 1));
        } else {
            fileNames.push_back(token);
        }
        start = end + 1;
    }

    if (start < input.size()) {
        size_t lastSlash = input.find_last_of('/');
        if (lastSlash != std::string::npos) {
            fileNames.push_back(input.substr(lastSlash + 1));
        } else {
            fileNames.push_back(input.substr(start));
        }
    }
}

void Processor::extractFileExtensions() {
    for (const auto &fileName: fileNames) {
        if (fileName.find('.') == std::string::npos || fileName[0] == '.') {
            continue;
        }

        const size_t dotPos = fileName.find_last_of('.');
        if (dotPos != std::string::npos && dotPos != fileName.size() - 1) {
            fileExtensions.insert(fileName.substr(dotPos + 1));
        }
    }
}
