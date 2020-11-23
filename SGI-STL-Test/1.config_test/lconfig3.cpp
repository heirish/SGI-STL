#include <iostream>
template <typename T>
class TestClass
{
public:
    static int _data;
};

template <>
int TestClass<int>::_data = 1;
template <>
int TestClass<char>::_data = 2;

int main()
{
#ifdef __STL_STATIC_TEMPLATE_MEMBER_BUG
    std::cout << "__STL_STATIC_TEMPLATE_MEMBER_BUG defined" << std::endl;
#else
    std::cout << "__STL_STATIC_TEMPLATE_MEMBER_BUG undefined" << std::endl;
#endif
    std::cout << TestClass<int>::_data << std::endl;
    std::cout << TestClass<char>::_data << std::endl;

    TestClass<int> obj1;
    TestClass<char> obj2;
    std::cout << obj1._data << std::endl;
    std::cout << obj2._data << std::endl;

    obj1._data = 3;
    obj2._data = 4;

    std::cout << obj1._data << std::endl;
    std::cout << obj2._data << std::endl;
}