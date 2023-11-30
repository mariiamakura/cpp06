#include "include/Serializer.hpp"

int main() {
    Data foo;
    uintptr_t result;

    foo.num = 5;
    result = Serializer::serialize(&foo);

    std::cout << "data address: " << &foo << " num: " << foo.num << std::endl;

    std::cout << "Reinterpreted data: " << result << std::endl;

    Data *deserialized = Serializer::deserialize(result);
    std::cout << "deserialized data address: " << deserialized << " num: " << deserialized->num << std::endl;
}
