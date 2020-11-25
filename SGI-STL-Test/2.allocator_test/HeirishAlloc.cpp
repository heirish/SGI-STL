#include "HeirishAlloc.h"
#include <iostream>
#include <vector>

int main()
{
    int ia[6] = {1, 2, 3, 4, 5, 6};
    unsigned int i;

    std::vector<int, Heirish::allocator<int>> iv(ia, ia + 6);
    for (auto item : iv)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}