#include <iostream>
#include <cstddef>

#ifndef __STL_TEMPLATE_NULL
#define __STL_TEMPLATE_NULL template<>
#endif

template <typename Key>
struct hash {
    void operator()() {
        std::cout <<"hash<T>" << std::endl;
    }
};

__STL_TEMPLATE_NULL 
struct hash<char>{
    void operator()() {
        std::cout << "hash<char>" << std::endl;
    }
};

__STL_TEMPLATE_NULL 
struct hash<unsigned char>{
    void operator()() {
        std::cout << "hash<unsigned char>" << std::endl;
    }
};

int main() {
    hash<long> h1;
    hash<char> h2;
    hash<unsigned char> h3;

    h1();
    h2();
    h3();
}