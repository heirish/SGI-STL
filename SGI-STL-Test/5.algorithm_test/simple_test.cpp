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
    std::cout << *(std::find_end(iv.begin(), iv.end(), iv2.begin(), iv2.end()) + 3) << std::endl;
    std::cout << *(std::find_first_of(iv.begin(), iv.end(), iv2.begin(), iv2.end()) + 3) << std::endl;

    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;

    std::generate(iv2.begin(), iv2.end(), even_by_two());
    std::for_each(iv2.begin(), iv2.end(), display<int>());
    std::cout << std::endl;

    std::generate_n(iv.begin(), 3, even_by_two());
    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;

    //只是将后面的非6进行了移动，实际并未删除，因此尾巴上可能会有遗留元素。
    auto newEnd = std::remove(iv.begin(), iv.end(), 6);
    std::cout << "new end" << *newEnd << std::endl;
    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;
    iv.erase(newEnd, iv.end());
    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;

    std::vector<int> iv3(12);
    std::remove_copy(iv.begin(), iv.end(), iv3.begin(), 7);
    std::for_each(iv3.begin(), iv3.end(), display<int>());
    std::cout << std::endl;
    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;

    //尾端可能有残余
    std::cout << "remove elements < 6" << std::endl;
    std::remove_if(iv.begin(), iv.end(), [](int x) { return std::less<int>()(x, 6); });
    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;

    std::cout << "remove copy elements < 7" << std::endl;
    iv3.clear();
    iv3.resize(12);
    std::remove_copy_if(iv.begin(), iv.end(), iv3.begin(), [](int x) { return std::less<int>()(x, 7); });
    std::for_each(iv3.begin(), iv3.end(), display<int>());
    std::cout << std::endl;

    std::cout << "replace 7 with 3" << std::endl;
    std::replace(iv.begin(), iv.end(), 7, 3);
    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;

    std::cout << "replace 3 with 5 and copy" << std::endl;
    iv3.clear();
    iv3.resize(10);
    std::replace_copy(iv.begin(), iv.end(), iv3.begin(), 3, 5);
    std::for_each(iv3.begin(), iv3.end(), display<int>());
    std::cout << std::endl;

    std::cout << "replace all elements <8 to 2" << std::endl;
    std::replace_if(
        iv.begin(), iv.end(), [](int x) { return std::less<int>()(x, 8); }, 2);
    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;

    std::cout << "replace 8 to 9" << std::endl;
    iv3.clear();
    iv3.resize(10);
    std::replace_copy_if(
        iv.begin(), iv.end(), iv3.begin(),
        [](int x) { return std::equal_to<int>()(x, 8); }, 9);
    std::for_each(iv3.begin(), iv3.end(), display<int>());
    std::cout << std::endl;

    std::cout << "reverse vector" << std::endl;
    std::reverse(iv.begin(), iv.end());
    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;

    std::cout << "reverse copy" << std::endl;
    iv3.clear();
    iv3.resize(10);
    std::reverse_copy(iv.begin(), iv.end(), iv3.begin());
    std::for_each(iv3.begin(), iv3.end(), display<int>());
    std::cout << std::endl;

    std::cout << "rotate vector" << std::endl;
    std::rotate(iv.begin(), iv.begin() + 4, iv.end());
    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;

    std::cout << "rotate copy" << std::endl;
    iv3.clear();
    iv3.resize(10);
    std::rotate_copy(iv.begin(), iv.begin() + 2, iv.end(), iv3.begin());
    std::for_each(iv3.begin(), iv3.end(), display<int>());
    std::cout << std::endl;

    std::cout << "寻找子序列:" << std::endl;
    std::vector<int> iv4{2, 8};
    std::cout << *(std::search(iv.begin(), iv.end(), iv4.begin(), iv4.end())) << std::endl;
    std::cout << *(std::search_n(iv.begin(), iv.end(), 2, 8)) << std::endl;

    std::cout << "连续3个小于10的子序列位置" << std::endl;
    std::cout << *(std::search_n(iv.begin(), iv.end(), 3, 10, std::less<int>())) << std::endl;

    std::cout << "将vec1中的全部元素交换到vec2, 注意vec2长度必须大于等于vec1" << std::endl;
    std::swap_ranges(iv4.begin(), iv4.end(), iv.begin());
    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;

    std::cout << "改变区间1的值，每个元素加1, 输出到区间2" << std::endl;
    std::transform(iv.begin(), iv.end(), iv.begin(), [](int x) { return x + 1; });
    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;

    std::cout << "将区间2的值加到区间1上, 输出到区间3上" << std::endl;
    std::transform(iv4.begin(), iv4.end(), iv.begin(), iv.begin(), std::plus<int>());
    std::for_each(iv.begin(), iv.end(), display<int>());
    std::cout << std::endl;

    std::cout << "求序列最大值，最小值" << std::endl;
    std::cout << "max:" << *(std::max_element(iv.begin(), iv.end())) << std::endl;
    std::cout << "min:" << *(std::min_element(iv.begin(), iv.end())) << std::endl;

    std::vector<int> iv5{1, 2, 3, 7, 8, 2};
    std::vector<int> iv6{19, 5, 9, 8, 3};
    std::sort(iv.begin(), iv.end());
    std::sort(iv6.begin(), iv6.end());
    std::cout << "must first sort, all elements of iv6 in iv ? "
              << std::includes(iv.begin(), iv.end(), iv6.begin(), iv6.end())
              << std::endl;

    std::cout << "将区间1的元素和区间2的元素合并到区间3，区间1，2必须先排序" << std::endl;
    std::sort(iv5.begin(), iv5.end());
    std::vector<int> iv7;
    iv7.resize(iv5.size() + iv6.size());
    std::merge(iv5.begin(), iv5.end(), iv6.begin(), iv6.end(), iv7.begin());
    std::for_each(iv7.begin(), iv7.end(), display<int>());
    std::cout << std::endl;

    auto partition_pos = std::partition(iv7.begin(), iv7.end(), even());
    std::cout << "partition pos:" << *partition_pos << std::endl;
    std::for_each(iv7.begin(), iv7.end(), display<int>());
    std::cout << std::endl;

    std::cout << "只删除连续的重复, 要删除所有重复的需要先排序" << std::endl;
    std::cout << "remove unique element, not deleted, similar with remove." << std::endl;
    auto new_end = std::unique(iv7.begin(), iv7.end());
    std::cout << "*new _end" << *new_end << std::endl;
    std::for_each(iv7.begin(), iv7.end(), display<int>());
    std::cout << std::endl;

    std::sort(iv7.begin(), iv7.end());
    std::vector<int> iv8;
    iv8.resize(iv7.size());
    std::unique_copy(iv7.begin(), iv7.end(), iv8.begin());
    std::for_each(iv8.begin(), iv8.end(), display<int>());
    std::cout << std::endl;
}
