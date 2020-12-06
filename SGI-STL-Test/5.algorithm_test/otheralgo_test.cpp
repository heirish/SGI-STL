#include <algorithm>
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>

struct even
{
    bool operator()(int x)
    {
        return x % 2 ? false : true;
    }
};

int main()
{
    std::vector<int> iv{12, 17, 20, 22, 23, 30, 33, 40};

    //return <= value的最大值
    auto ite = std::lower_bound(iv.begin(), iv.end(), 21);
    if (ite != iv.end())
    {
        std::cout << "lower_bound of 21 in iv is :" << *ite << std::endl;
    }
    ite = std::lower_bound(iv.begin(), iv.end(), 22);
    if (ite != iv.end())
    {
        std::cout << "lower_bound of 22 in iv is :" << *ite << std::endl;
    }
    //return > value的第一个值
    ite = std::upper_bound(iv.begin(), iv.end(), 21);
    if (ite != iv.end())
    {
        std::cout << "upper_bound of 21 in iv is :" << *ite << std::endl;
    }
    ite = std::upper_bound(iv.begin(), iv.end(), 22);
    if (ite != iv.end())
    {
        std::cout << "upper_bound of 22 in iv is :" << *ite << std::endl;
    }

    std::cout << "33 in iv ? "
              << std::binary_search(iv.begin(), iv.end(), 33) << std::endl;
    std::cout << "34 in iv ? "
              << std::binary_search(iv.begin(), iv.end(), 34) << std::endl;

    std::cout << "next_permuation:" << std::endl;
    std::next_permutation(iv.begin(), iv.end());
    std::copy(iv.begin(), iv.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "prev_permuation:" << std::endl;
    std::prev_permutation(iv.begin(), iv.end());
    std::copy(iv.begin(), iv.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "random_shuffle:" << std::endl;
    std::random_shuffle(iv.begin(), iv.end());
    std::copy(iv.begin(), iv.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "partial_sort:" << std::endl;
    std::partial_sort(iv.begin(), iv.begin() + 4, iv.end());
    std::copy(iv.begin(), iv.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "sort asc default:" << std::endl;
    std::sort(iv.begin(), iv.end());
    std::copy(iv.begin(), iv.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "sort desc:" << std::endl;
    std::sort(iv.begin(), iv.end(), std::greater<int>());
    std::copy(iv.begin(), iv.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    iv.push_back(22);
    iv.push_back(30);
    iv.push_back(17);

    std::cout << "stable sort:" << std::endl;
    std::stable_sort(iv.begin(), iv.end());
    std::copy(iv.begin(), iv.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    auto [ite1, ite2] = std::equal_range(iv.begin(), iv.end(), 23);
    std::cout << "equal_range of 23:" << *ite1 << "," << *ite2 << std::endl;
    auto [ite3, ite4] = std::equal_range(iv.begin(), iv.end(), 25);
    std::cout << "equal_range of 25:" << *ite3 << "," << *ite4 << std::endl;

    std::cout << "random_shuffle" << std::endl;
    std::random_shuffle(iv.begin(), iv.end());
    std::copy(iv.begin(), iv.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "nth_element:" << std::endl;
    std::nth_element(iv.begin(), iv.begin() + 4, iv.end());
    std::copy(iv.begin(), iv.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "nth_element:" << std::endl;
    std::nth_element(iv.begin(), iv.begin() + 5, iv.end(), std::greater<int>());
    std::copy(iv.begin(), iv.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "stable partition:" << std::endl;
    std::stable_partition(iv.begin(), iv.end(), even());
    std::copy(iv.begin(), iv.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}