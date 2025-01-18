#include <fstream>
#include <iostream>
#include <unordered_map>

#include "gitattributes_generator.hpp"

void generateGitattributes(const std::unordered_set<std::string> &extensions) {
    std::ofstream file("../test_attributes.txt");
    if (!file) {
        std::cerr << "Error: Could not create test_attributes.txt file." << std::endl;
        return;
    }

    file << "* text=auto\n";

    const std::unordered_map<std::string, std::string> extensionTypes = {
            {"png", "binary"}, {"jpg", "binary"}, {"gif", "binary"}, {"pdf", "binary"}, {"env", "export-ignore"}};

    const std::unordered_set<std::string> cppExtensions = {"cpp", "c++", "hpp", "hxx"};

    for (const auto &ext: extensions) {
        std::string type = "text";
        std::string diff = "diff=" + ext;

        if (extensionTypes.contains(ext)) {
            type = extensionTypes.at(ext);
            if (ext == "env") {
                file << "*." << ext << " " << type << "\n";
                continue;
            }
        }

        if (cppExtensions.contains(ext)) {
            diff = "diff=cpp";
        }

        file << "*." << ext << " " << type << " " << diff << "\n";
    }

    file.close();
    std::cout << "test_attributes.txt file generated successfully!" << std::endl;
}
