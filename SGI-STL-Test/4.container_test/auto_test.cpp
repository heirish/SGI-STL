//https://crascit.com/2016/08/15/avoiding-copies-and-moves-with-auto/
#include <iostream>
#include <vector>
#include "A.h"

A getA(int i)
{
    A result(i);
    return result;
}
std::vector<A> getVecA()
{
    std::vector<A> avec;
    avec.reserve(3);
    avec.emplace_back(1);
    avec.emplace_back(2);
    avec.emplace_back(3);
    return avec;
}
int main()
{
    auto a = A(42);    //value constructor
    A aa = A(42);      //value constructor
    auto b = getA(42); //value constructor
    A bb;              //default constructor
    bb = aa;           //copy assignment
    auto bbb = aa;     //copy constructor

    auto vec = getVecA(); //three value constructor
    std::cout << "------" << std::endl;
    for (auto item : vec) //three copy constructor + destructor
    {
        ;
    }

    std::cout << "------" << std::endl;
    for (const auto& item:vec) {//no constructor or destructor
        ;
    }
    std::cout << "------" << std::endl;
    for (auto& item:vec) {//no constructor or destructor
        ;
    }
}