#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <functional>
#include <iterator> //ostream_iterator
#include <cmath>

int main()
{
    int ia[5] = {1, 2, 3, 4, 5};
    std::vector<int> ivec(ia, ia + 5);

    std::cout << std::accumulate(ivec.begin(), ivec.end(), 0) << std::endl;
    std::cout << std::accumulate(ivec.begin(), ivec.end(), 0, std::minus<int>()) << std::endl;

    std::cout << std::inner_product(ivec.begin(), ivec.end(), ivec.begin(), 10) << std::endl;
    std::cout << std::inner_product(ivec.begin(), ivec.end(), ivec.begin(), 10,
                                    std::minus<int>(), std::plus<int>())
              << std::endl;

    std::ostream_iterator<int> oite(std::cout, " ");
    std::partial_sum(ivec.begin(), ivec.end(), oite);
    std::partial_sum(ivec.begin(), ivec.end(), oite, std::minus<int>());

    std::adjacent_difference(ivec.begin(), ivec.end(), oite);
    std::adjacent_difference(ivec.begin(), ivec.end(), oite, std::plus<int>());

    std::cout << std::pow(10, 3) << std::endl;

    int n = 3;
    std::iota(ivec.begin(), ivec.end(), n);
    for (const auto &item : ivec)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    std::list<int> ilist(10);
    std::iota(ilist.begin(), ilist.end(), 10);
    for (const auto &item : ilist)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}