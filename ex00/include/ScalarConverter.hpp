#pragma once

#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#define RESET   "\033[0m"
#define RED     "\033[31m"

class ScalarConverter {
public:
    static void convert(const std::string &literal);

private:
    ScalarConverter() {};
};