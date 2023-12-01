#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <cstdlib>

A *newA(void) {
    return (new A);
}

B *newB(void) {
    return (new B);
}

C *newC(void) {
    return (new C);
}

Base *generate(void) {
    srand(time(NULL));
    char c = "ABC"[rand() % 3];

    std::cout << "Type : " << c << " generated" << std::endl;
    Base *(*all_foo[3])() = {reinterpret_cast<Base*(*)()>(newA), reinterpret_cast<Base*(*)()>(newB), reinterpret_cast<Base*(*)()>(newC)};
    char name[3] = {'A', 'B', 'C'};
    for (int i = 0; i < 3; i++) {
        if (c == name[i])
            return(all_foo[i]());
    }
    return (NULL);
}

void identify(Base *p) {

    std::cout << "Identified as class ";
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "invalid" << std::endl;
}

void identify(Base &p) {
    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "reference to A" << std::endl;
    } catch (...) {}

    try {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "reference to B" << std::endl;
    } catch (...) {}

    try {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "reference to C" << std::endl;
    } catch (...) {}
}