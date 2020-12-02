#include "A.h"
#include <iostream>

A::A() : _value(0)
{
    std::cout << "Default constructor" << std::endl;
}
A::A(int i) : _value(0)
{
    std::cout << "Value constructor" << std::endl;
}
A::A(const A &other)
{
    this->_value = other._value;
    std::cout << "copy constructor" << std::endl;
}
A::A(A &&other)
{
    _value = std::move(other._value);
    std::cout << "move constructor" << std::endl;
}
A::~A()
{
    std::cout << "destructor" << std::endl;
}
A &A::operator=(const A &other)
{
    this->_value = other._value;
    std::cout << "copy assignment" << std::endl;
    return *this;
}
A &A::operator=(A &&other)
{
    std::cout << "move assignment" << std::endl;
    this->_value = std::move(other._value);
    return *this;
}