#include <gtest/gtest.h>
#include <iostream>
#include "../include/processor.h"

// Тест для проверки обработки входных данных
TEST(ProcessorTests, ProcessInput) {
    const std::string input = "dir1/file1.txt;LICENSE;.gitignore;dir2/file2.jpg;README;dir3/subdir/.hiddenfile";
    Processor processor(input);
    processor.process();

    // Проверяем корректность извлечения имен файлов
    const auto &fileNames = processor.getFileNames();
    const std::vector<std::string> expectedFileNames = {
        "file1.txt", "LICENSE", ".gitignore", "file2.jpg", "README", ".hiddenfile"
    };
    EXPECT_EQ(fileNames, expectedFileNames);

    // Проверяем корректность извлечения расширений файлов
    const auto &fileExtensions = processor.getFileExtensions();
    const std::set<std::string> expectedExtensions = {"txt", "jpg"};
    EXPECT_EQ(fileExtensions, expectedExtensions);

    std::cout << "[SUCCESS] ProcessInput test passed!" << std::endl;
}

// Тест для пустого ввода
TEST(ProcessorTests, EmptyInput) {
    Processor processor("");
    processor.process();

    EXPECT_TRUE(processor.getFileNames().empty());
    EXPECT_TRUE(processor.getFileExtensions().empty());

    std::cout << "[SUCCESS] EmptyInput test passed!" << std::endl;
}

// Тест для ввода без разделителей
TEST(ProcessorTests, SingleFileInput) {
    const std::string input = "file1.txt";
    Processor processor(input);
    processor.process();

    EXPECT_EQ(processor.getFileNames(), std::vector<std::string>{"file1.txt"});
    EXPECT_EQ(processor.getFileExtensions(), std::set<std::string>{"txt"});

    std::cout << "[SUCCESS] SingleFileInput test passed!" << std::endl;
}

// Тест для ввода с файлами без расширений
TEST(ProcessorTests, FilesWithoutExtensions) {
    const std::string input = "file1;file2;file3";
    Processor processor(input);
    processor.process();

    const auto &actualFileNames = processor.getFileNames();
    const std::vector<std::string> expectedFileNames = {"file1", "file2", "file3"};

    ASSERT_EQ(actualFileNames.size(), expectedFileNames.size());
    for (size_t i = 0; i < actualFileNames.size(); ++i) {
        EXPECT_EQ(actualFileNames[i], expectedFileNames[i]);
    }

    EXPECT_TRUE(processor.getFileExtensions().empty());

    std::cout << "[SUCCESS] FilesWithoutExtensions test passed!" << std::endl;
}
