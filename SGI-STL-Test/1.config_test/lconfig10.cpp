#include <iostream>
#include <cstddef>

class alloc
{
};

template <typename T, typename Alloc = alloc, size_t BufSize = 0>
class deque
{
public:
    deque() { std::cout << "deque" << std::endl; }
};

template <typename T, typename Sequence = deque<T>>
class stack
{
public:
    stack() { std::cout << "stack" << std::endl; }

private:
    Sequence c;
};

int main()
{
#ifdef __STL_LIMITED_DEFAULT_TEMPLATES
    std::cout << "__STL_LIMITED_DEFAULT_TEMPLATES defined" << std::endl;
#else //__STL_LIMITED_DEFAULT_TEMPLATES
    std::cout << "__STL_LIMITED_DEFAULT_TEMPLATES undefined" << std::endl;
#endif //__STL_LIMITED_DEFAULT_TEMPLATES
    stack<int> x;
}
