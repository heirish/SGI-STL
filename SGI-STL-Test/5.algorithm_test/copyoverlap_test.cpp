#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

int main()
{
    //end of output overlap with input, OK
    {
        int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        std::for_each(ia, ia + 9, [](const int &x) { std::cout << x << " "; });
        std::cout << std::endl;
        std::copy(ia + 2, ia + 7, ia);
        std::for_each(ia, ia + 9, [](const int &x) { std::cout << x << " "; });
        std::cout << std::endl;
    }
    //start of output overlap with input, might not OK
    {
        int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        std::for_each(ia, ia + 9, [](const int &x) { std::cout << x << " "; });
        std::cout << std::endl;
        std::copy(ia + 2, ia + 7, ia + 4);
        std::for_each(ia, ia + 9, [](const int &x) { std::cout << x << " "; });
        std::cout << std::endl;
    }
    {
        std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8};
        std::copy(ivec.begin() + 2, ivec.begin() + 7, ivec.begin());
        std::for_each(ivec.begin(), ivec.end(), [](const int &x) { std::cout << x << " "; });
        std::cout << std::endl;
        std::for_each(ivec.begin(), ivec.end(), [](const int &x) { std::cout << x << " "; });
        std::cout << std::endl;
    }
    {
        std::list<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8};
        std::list<int>::const_iterator start = ivec.begin();
        std::list<int>::const_iterator end = ivec.begin();
        std::advance(start, 2);
        std::advance(end, 7);
        std::copy(start, end, ivec.begin());
        std::for_each(ivec.begin(), ivec.end(), [](const int &x) { std::cout << x << " "; });
        std::cout << std::endl;
        std::for_each(ivec.begin(), ivec.end(), [](const int &x) { std::cout << x << " "; });
        std::cout << std::endl;
    }
}