#include <functional>
#include <iostream>

int main() {
    std::logical_and<int> andobj;
    std::logical_or<int> orobj;
    std::logical_not<int> notobj;

    std::cout << andobj(1,2) << std::endl;
    std::cout << orobj(0,0) << std::endl;
    std::cout << notobj(2) << std::endl;

    std::cout << std::logical_and<bool>()(true, true) << std::endl;
    std::cout << std::logical_or<bool>()(true, false) << std::endl;
    std::cout << std::logical_not<bool>()(false) << std::endl;
}