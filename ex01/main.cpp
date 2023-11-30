#include "include/Serializer.hpp"

int main() {
    Data foo;
    uintptr_t result;

    foo.level = 5;
    foo.health = 200;
    foo.points = 795;
    foo.age = 26;


    //uintptr_t cStyle = (uintptr_t)&foo;
    result = Serializer::serialize(&foo);

    std::cout << "data address: " << &foo << " level: " << foo.level << std::endl;

    std::cout << "Reinterpreted data: " << result << std::endl;
    //std::cout << "cStyle: " << cStyle << std::endl;

    //printing all data at once
//    for (int i = 0; i < (int)sizeof(Data); i+=4) {
//        std::cout << *reinterpret_cast<int *>(result + i) << ' ' << std::endl;
//    }

//    int *ptr = reinterpret_cast<int *>(&foo);
//    for (int i = 0; i < (int)sizeof(Data); i += 4) {
//        std::cout << *(ptr + i / sizeof(int)) << ' ';
//    }
//    std::cout << std::endl;


    Data *deserialized = Serializer::deserialize(result);
    std::cout << "deserialized data address: " << deserialized << " level: " << deserialized->level << std::endl;
}
