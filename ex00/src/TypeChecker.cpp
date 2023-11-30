#include "../include/TypeChecker.hpp"

 bool isChar(const std::string &literal) {
    if (literal.length() != 1)
        return (false);
    if (literal.at(0) < std::numeric_limits<char>::min() ||
        literal.at(0) > std::numeric_limits<char>::max() ||
        isdigit(literal.at(0)) != 0)
        return (false);
    return (true);
}

bool isInt(const std::string &literal) {
    int i = 0;
    int len = literal.length();

    if (literal.at(0) == '-' || literal.at(0) == '+')
        i++;
    while (i < len) {
        if (isdigit(literal.at(i)) == 0)
            return false;
        i++;
    }
    return true;
}


bool isPseudoLit(const std::string &literal)
{
    return (literal == "-inff" || literal == "+inff" || literal == "nanf"
            || literal == "-inf" || literal == "+inf"  || literal == "nan");
}


bool isFloat(const std::string &literal) {
    int lastDig = literal.length() - 1;
    bool coma = false;
    int i = 0;

    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return (true);
    if (literal.at(lastDig) != 'f')
        return (false);
    if (literal.at(0) == '-' || literal.at(0) == '+')
        i++;
    while (i < lastDig)
    {
        if (literal.at(i) == '.' && coma)
            return (false);
        if (literal.at(i) != '.' && !isdigit(literal.at(i)))
            return (false);
        if (literal.at(i) == '.')
            coma = true;
        i++;
    }
    if (!coma)
        return (false);
    return (true);
}


bool isDouble(const std::string &literal) {
    bool coma = false;
    int i = 0;

    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return (true);
    if (literal.at(0) == '-' || literal.at(0) == '+')
        i++;
    while (i < (int)literal.length())
    {
        if (literal.at(i) == '.' && coma)
            return (false);
        if (literal.at(i) != '.' && !isdigit(literal.at(i)))
            return (false);
        if (literal.at(i) == '.')
            coma = true;
        i++;
    }
    if (!coma)
        return (false);
    return (true);
}
