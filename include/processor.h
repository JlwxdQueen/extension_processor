#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <set>
#include <string>
#include <vector>

class Processor {
    const std::string input;
    std::set<std::string> fileExtensions;
    std::vector<std::string> fileNames;

public:
    explicit Processor(std::string input);
    void process();

    [[nodiscard]] const std::set<std::string> &getFileExtensions() const;
    [[nodiscard]] const std::vector<std::string> &getFileNames() const;

private:
    void extractFileNames();
    void extractFileExtensions();
};

#endif
