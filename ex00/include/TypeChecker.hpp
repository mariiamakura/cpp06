#pragma once

#include <limits>
#include <string>
#include <cstdlib>
#include <cmath>

bool isChar(const std::string &literal);
bool isInt(const std::string &literal);
bool isPseudoLit(const std::string &literal);
bool isFloat(const std::string &literal);
bool isDouble(const std::string &literal);