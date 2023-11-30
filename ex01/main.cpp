#include "include/Serializer.hpp"

int main() {
    Data foo;
    uintptr_t result;

    foo.num = 5;

    //uintptr_t cStyle = (uintptr_t)&foo;
    result = Serializer::serialize(&foo);

    std::cout << "data address: " << &foo << " num: " << foo.num << std::endl;

    std::cout << "Reinterpreted data: " << result << std::endl;
    //std::cout << "cStyle: " << cStyle << std::endl;

    Data *deserialized = Serializer::deserialize(result);
    std::cout << "deserialized data address: " << deserialized << " num: " << deserialized->num << std::endl;
}
