#include <set>
#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
    int ia1[6] = {1, 3, 5, 7, 9, 11};
    int ia2[7] = {1, 1, 2, 3, 5, 8, 13};

    std::multiset<int> iset1(ia1, ia1 + 6);
    std::multiset<int> iset2(ia2, ia2 + 7);

    std::for_each(iset1.begin(), iset1.end(), [](const int &x) { std::cout << x << ' '; });
    std::cout << std::endl;
    std::for_each(iset2.begin(), iset2.end(), [](const int &x) { std::cout << x << ' '; });
    std::cout << std::endl;

    std::cout << "Union of s1 and s2:";
    std::set_union(iset1.begin(), iset1.end(), iset2.begin(), iset2.end(),
                   std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;               

    std::cout << "Intersection of s1 and s2:";
    std::set_intersection(iset1.begin(), iset1.end(), iset2.begin(), iset2.end(),
                          std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;               

    std::cout << "Difference of s1 and s2:";
    std::set_difference(iset1.begin(), iset1.end(), iset2.begin(), iset2.end(),
                        std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;               

    std::cout << "Difference of s1 and s2:";
    std::set_symmetric_difference(iset1.begin(), iset1.end(), iset2.begin(), iset2.end(),
                                  std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;               
}