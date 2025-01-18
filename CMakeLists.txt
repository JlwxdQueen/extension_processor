cmake_minimum_required(VERSION 3.10)

# Название проекта
project(Extension_Processor LANGUAGES CXX)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Основная библиотека
add_library(ProcessorLib STATIC
        include/processor.hpp
        src/processor.cpp

        src/generator/gitattributes_generator.hpp
        src/generator/gitattributes_generator.cpp
)

# Основной исполняемый файл
add_executable(Processor src/main.cpp)
target_link_libraries(Processor PRIVATE ProcessorLib)

# Проверяем, нужен ли нам тестовый код
if (EXISTS "${CMAKE_SOURCE_DIR}/tests/test_processor.cpp")
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
endif ()
