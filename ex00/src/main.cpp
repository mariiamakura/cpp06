#include "../include/ScalarConverter.hpp"

int main(int ac, char **av) {
    //not possible to instantiate
    //ScalarConverter test;

    if (ac != 2) {
        std::cerr << RED << "Wrong number of arguments" << RESET << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
    return (0);
}