#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>

template <typename T>
struct display
{
    void operator()(const T &x) const
    {
        std::cout << x << " ";
    }
};

struct even
{
    bool operator()(int x) const
    {
        return x % 2 ? false : true;
    }
};

class even_by_two
{
public:
    int operator()() const
    {
        return _x += 2;
    }

private:
    static int _x;
};
//可以不初始化吗，编译器是否会给默认值。
//不可以，编译会报错，有人说这里是声明?
int even_by_two::_x = 0;

int main()
{
    //std::cout << even_by_two()() << std::endl;
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8};
    int length = sizeof(ia) / sizeof(int);
    std::vector<int> iv(ia, ia + length);

    std::cout << "first neighbour equal value:"
              << *std::adjacent_find(iv.begin(), iv.end()) << std::endl;
    std::cout << "first neighbour equal value:"
              << *std::adjacent_find(iv.begin(), iv.end(), std::equal_to<int>()) << std::endl;

    std::cout << "#of 6s:"
              << std::count(iv.begin(), iv.end(), 6) << std::endl;
    std::cout << "#of elements <7:"
              << std::count_if(iv.begin(), iv.end(), [](int x) { return std::less<int>()(x, 7); })
              << std::endl;

    std::cout << "fist element greater than 2 : "
              << *std::find_if(iv.begin(), iv.end(), [](int x) { return std::greater<int>()(x, 2); })
              << std::endl;

    std::vector<int> iv2(ia + 6, ia + 8);
    std::cout << *(std::find_end(iv.begin(), iv.end(), iv2.begin(), iv2.end())+3) << std::endl;
    std::cout << *(std::find_first_of(iv.begin(), iv.end(), iv2.begin(), iv2.end())+3) << std::endl;

    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;

    std::generate(iv2.begin(), iv2.end(), even_by_two());
    std::for_each(iv2.begin(), iv2.end(), display<int>());
    std::cout << std::endl;

    std::generate_n(iv.begin(), 3, even_by_two());
    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;

}
