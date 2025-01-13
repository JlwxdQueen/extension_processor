cmake_minimum_required(VERSION 3.10)

# Название проекта
project(ProcessorProject LANGUAGES CXX)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основная библиотека
add_library(ProcessorLib STATIC
        src/processor.cpp
        include/processor.h
)

# Основной исполняемый файл
add_executable(Processor src/main.cpp)
target_link_libraries(Processor PRIVATE ProcessorLib)

# Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

# Подключение Google Test
FetchContent_MakeAvailable(googletest)

# Включение тестирования
enable_testing()

# Добавление тестов
add_executable(ProcessorTests tests/test_processor.cpp)

# Линковка с Google Test и основной библиотекой
target_link_libraries(ProcessorTests PRIVATE gtest gtest_main ProcessorLib)

# Регистрация тестов
add_test(NAME ProcessorTests COMMAND ProcessorTests)
