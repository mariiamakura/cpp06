#include "include/Base.hpp"

void identify(Base *p);
Base *generate(void);
void identify(Base &p);

int main() {
    Base *c;

    c = generate();

    identify(c);
    identify(*c);

    delete c;
}

