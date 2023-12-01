#include "../include/ScalarConverter.hpp"
#include "../include/TypeChecker.hpp"

static void printChar(const char c) {
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f"<< std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void charPossible(int res){
    if (res < 256 && res >= 0 && isprint(res))
        std::cout << "char: '" << static_cast<char>(res) << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

static void printInt(const std::string &literal) {
    const char *str = &literal[0];
    int res = std::atoi(str);

    charPossible(res);
    std::cout << "int: " << res << std::endl;
    std::cout << "float: " << static_cast<float>(res) << ".0f"<< std::endl;
    std::cout << "double: " << static_cast<double>(res) << ".0" << std::endl;
}

static void printPseudo(const std::string &literal, char type) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (type == 'f') {
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
    }
    else if (type == 'd') {
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
    }
}

static void normalFloat(const std::string &literal)
{
    const char *str = &literal[0];
    float res = std::atof(str);

    charPossible(res);
    std::cout << "int: " << static_cast<int>(res) << std::endl;
    if (std::fmod(res, 1.0) == 0.0) {
        std::cout << "float: " << res << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(res) << ".0"<< std::endl;
    } else {
        std::cout << "float: " << res << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(res) << std::endl;
    }
}

static void printFloat(const std::string &literal)
{
    if (isPseudoLit(literal))
        printPseudo(literal, 'f');
    else
        normalFloat(literal);
}

static char getType(const std::string &literal) {
    if (isChar(literal))
        return ('c');
    else if (isInt(literal))
        return ('i');
    else if (isFloat(literal))
        return ('f');
    else if (isDouble(literal))
        return ('d');
    return('e');
}

static void normalDouble(const std::string &literal)
{
    const char *str = &literal[0];
    double res = std::atof(str);

    charPossible(res);
    std::cout << "int: " << static_cast<int>(res) << std::endl;
    if (std::fmod(res, 1.0) == 0.0) {
        std::cout << "float: " << static_cast<float>(res) << ".0f" << std::endl;
        std::cout << "double: " << res << ".0"<< std::endl;
    } else {
        std::cout << "float: " << static_cast<float>(res) << "f" << std::endl;
        std::cout << "double: " << res << std::endl;
    }
}

static void printDouble(const std::string &literal) {
    if (isPseudoLit(literal))
        printPseudo(literal, 'd');
    else
        normalDouble(literal);
}

void ScalarConverter::convert(const std::string &literal) {
    const char &type = getType(literal);

    if (type == 'c')
        printChar(literal.at(0));
    else if (type == 'i')
        printInt(literal);
    else if (type == 'f')
        printFloat(literal);
    else if (type == 'd')
        printDouble(literal);
    else
        std::cout << "Unknown type" << std::endl;
}