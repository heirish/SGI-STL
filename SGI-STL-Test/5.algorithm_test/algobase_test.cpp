#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>

template <typename T>
struct display
{
    void operator()(const T &x) const
    {
        std::cout << x << ' ';
    }
};

int main()
{
    int ia[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    std::vector<int> iv1(ia, ia + 5);
    std::vector<int> iv2(ia, ia + 9);

    const auto [iter1, iter2] = std::mismatch(iv1.begin(), iv1.end(), iv2.begin());
    if (iter1 != iv1.end())
    {
        std::cout << "first mismatch from iv1 " << *iter1 << std::endl;
    }
    if (iter2 != iv1.end())
    {
        std::cout << "first mismatch from iv2 " << *iter2 << std::endl;
    }

    std::cout << "iv1 == first len(iv1) of iv2 ? "
              << std::equal(iv1.begin(), iv1.end(), iv2.begin()) << std::endl;
    std::cout << "iv1 == first len(iv1) of ia[3, ....) ? "
              << std::equal(iv1.begin(), iv1.end(), &ia[3]) << std::endl;
    std::cout << "each iem of iv1 < first len(iv1) of ia[3, ....) ? "
              << std::equal(iv1.begin(), iv1.end(), &ia[3], std::less<int>()) << std::endl;

    //functor
    std::fill(iv1.begin(), iv1.end(), 9);
    for_each(iv1.begin(), iv1.end(), display<int>());
    std::cout << std::endl;

    //lambda
    std::fill_n(iv1.begin(), 3, 7);
    for_each(iv1.begin(), iv1.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;

    std::vector<int>::iterator ite1 = iv1.begin();
    std::vector<int>::iterator ite2 = ite1;
    std::advance(ite2, 3);
    std::cout << "before iter_swap, *ite1=" << *ite1 << ", *ite2=" << *ite2 << std::endl;
    std::iter_swap(ite1, ite2);
    std::cout << "after iter_swap, *ite1=" << *ite1 << ", *ite2=" << *ite2 << std::endl;
    for_each(iv1.begin(), iv1.end(), [](int x) { std::cout << x << ' '; });

    std::cout << std::max(*ite1, *ite2) << std::endl;
    std::cout << std::min(*ite1, *ite2) << std::endl;

    std::cout << "before begin swap:" << std::endl;
    for_each(iv1.begin(), iv1.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;
    for_each(iv2.begin(), iv2.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;
    std::swap(*iv1.begin(), *iv2.begin());
    std::cout << "after begin swap:" << std::endl;
    for_each(iv1.begin(), iv1.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;
    for_each(iv2.begin(), iv2.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;

    std::string stra1[] = {"Jamie", "JJHou", "Jason"};
    std::string stra2[] = {"Jamie", "JJhou", "Jerry"};
    std::cout << "stra1 < stra2 ? "
              << std::lexicographical_compare(stra1, stra1 + 2, stra2, stra2 + 2) << std::endl;
    std::cout << "stra1 not grater than stra2 ? "
              << std::lexicographical_compare(stra1, stra1 + 2, stra2, stra2 + 2,
                                              std::greater<std::string>())
              << std::endl;
}