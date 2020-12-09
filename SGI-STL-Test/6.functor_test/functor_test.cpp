#include <functional>
#include <iostream>

int main() {
    std::plus<int> plusobj;
    std::minus<int> minusobj;
    std::multiplies<int> multipliesobj;
    std::divides<int> dividesobj;
    std::modulus<int> modulusobj;
    std::negate<int> negateobj;

    std::cout << plusobj(3,5) << std::endl;
    std::cout << minusobj(3,5) << std::endl;
    std::cout << multipliesobj(3,5) << std::endl;
    std::cout << dividesobj(3,5) << std::endl;
    std::cout << modulusobj(3,5) << std::endl;
    std::cout << negateobj(3) << std::endl;

    std::cout << std::plus<int>()(3,5) << std::endl;
    std::cout << std::minus<int>()(3,5) << std::endl;
    std::cout << std::multiplies<int>()(3,5) << std::endl;
    std::cout << std::divides<int>()(3,5) << std::endl;
    std::cout << std::modulus<int>()(3,5) << std::endl;
    std::cout << std::negate<int>()(3) << std::endl;
}