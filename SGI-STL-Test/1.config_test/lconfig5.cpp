#include <iostream>
template <class I, class O>
struct TestClass
{
    TestClass() { std::cout << "I,O" << std::endl; }
};

//偏特化
template <class T>
struct TestClass<T *, T *>
{
    TestClass() { std::cout << "T*, T*" << std::endl; }
};

//偏特化
template <class T>
struct TestClass<const T *, T *>
{
    TestClass() { std::cout << "const T*, T*" << std::endl; }
};

int main()
{
#ifdef __STL_CLASS_PARTIAL_SPECIALIZATION
    std::cout << "__STL_CLASS_PARTIAL_SPECIALIZATION defined" << std::endl;
#else
    std::cout << "__STL_CLASS_PARTIAL_SPECIALIZATION undefined" << std::endl;
#endif
    TestClass<int, char> obj1;
    TestClass<int *, char *> obj2;
    TestClass<const int *, char *> obj3;
}