#include <iostream>
#include <cstddef>

class alloc
{
};

inline size_t __deque_buf_size(size_t n, size_t sz)
{
    return n != 0 ? n : (sz < 512 ? size_t(512 / sz) : size_t(1));
}

template <typename T, typename Ref, typename Ptr, size_t BufSize>
struct __deque_iterator
{
    typedef __deque_iterator<T, T &, T *, BufSize> iterator;
    typedef __deque_iterator<T, const T &, const T *, BufSize> const_iterator;
    static size_t buff_size() { return __deque_buf_size(BufSize, sizeof(T)); };
};

template <typename T, typename Alloc = alloc, size_t BufSize = 0>
class deque
{

public:
    typedef __deque_iterator<T, T &, T *, BufSize> iterator;
};

int main()
{
#ifdef __STL_NON_TYPE_TMPL_PARAM_BUG
    std::cout << "__STL_NON_TYPE_TMPL_PARAM_BUG defined." << std::endl;
#else //__STL_NON_TYPE_TMPL_PARAM_BUG
    std::cout << "__STL_NON_TYPE_TMPL_PARAM_BUG undefined." << std::endl;
#endif //__STL_NON_TYPE_TMPL_PARAM_BUG
    std::cout << deque<int>::iterator::buff_size() << std::endl;
    std::cout << deque<int, alloc, 64>::iterator::buff_size() << std::endl;
}
