#include <iostream>

class alloc
{
};

template <typename T, class Alloc = alloc>
class vector
{
public:
    void swap(vector<T, Alloc> &) { std::cout << "swap()" << std::endl; }
};

int main()
{
#ifdef __STL_FUNCTION_TMPL_PARTIAL_ORDER
    std::cout << "__STL_FUNCTION_TMPL_PARTIAL_ORDER defined." << std::endl;
#else
    std::cout << "__STL_FUNCTION_TMPL_PARTIAL_ORDER undefined." << std::endl;
#endif

    vector<int> x, y;
    x.swap(y);
    //std::swap(x, y);
}