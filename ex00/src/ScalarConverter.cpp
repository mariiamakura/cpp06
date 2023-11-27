#include "../include/ScalarConverter.hpp"

static bool isChar(const std::string &literal) {
    if (literal.length() != 1)
        return (false);
    if (literal.at(0) < std::numeric_limits<char>::min() ||
        literal.at(0) > std::numeric_limits<char>::max() ||
            isdigit(literal.at(0)) != 0)
        return (false);
    return (true);
}
static void printChar(const char c) {
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f"<< std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static bool isInt(const std::string &literal) {
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

static void printInt(const std::string &literal) {
    const char *str = &literal[0];
    int res = std::atoi(str);

    if (isprint(res))
        std::cout << "char: '" << static_cast<char>(res) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << res << std::endl;
    std::cout << "float: " << static_cast<float>(res) << ".0f"<< std::endl;
    std::cout << "double: " << static_cast<double>(res) << ".0" << std::endl;
}

static char getType(const std::string &literal) {
    if (isChar(literal))
        return ('c');
    else if (isInt(literal))
        return ('i');
    return('e');
}

void ScalarConverter::convert(const std::string &literal) {
    const char &type = getType(literal);

    //make arr [c, i, f, d, e] with pointers to print functions

    //std::cout << type << std::endl;
    if (type == 'c')
        printChar(literal.at(0));
    else if (type == 'i')
        printInt(literal);
}