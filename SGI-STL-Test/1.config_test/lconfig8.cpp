#include <iostream>

class alloc
{
};

template <typename T, typename Alloc = alloc>
class vector
{

public:
    typedef T value_type;
    typedef value_type *iterator;

    template <typename I>
    void insert(iterator position, I first, I last)
    {
        std::cout << "insert()" << std::endl;
    }
};

int main() {
    #ifdef __STL_MEMBER_TEMPLATES
    std::cout << "__STL_MEMBER_TEMPLATES defined." << std::endl;
    #else
    std::cout << "__STL_MEMBER_TEMPLATES undefined." << std::endl;
    #endif

    int ia[5] = {1,2,3,4,5};
    vector<int> x;
    vector<int>::iterator ite;
    x.insert(ite, ia, ia+5);
}