#pragma once

#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"

class ScalarConverter {
public:
    static void convert(const std::string &literal);

private:
    ScalarConverter() {};
};