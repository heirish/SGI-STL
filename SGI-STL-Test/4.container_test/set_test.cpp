#include <iostream>
#include <set>
#include <algorithm>

template <typename T>
void DispalyIteratorable(const T &iteratorable)
{
    std::cout << "size:" << iteratorable.size() << std::endl;
    for (const auto &item : iteratorable)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
int main()
{
    int i;
    int ia[6] = {4, 7, 2, 1, 0, 1};
    std::set<int> iset(ia, ia + 6);
    std::set<int>::const_iterator it = iset.begin();
    for (; it != iset.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    DispalyIteratorable(iset);

    iset.insert(5);
    DispalyIteratorable(iset);
    iset.erase(1);
    DispalyIteratorable(iset);

    //可以使用std::find查找元素，但不推荐，使用set自带的find效率更高
    std::set<int>::iterator ite = std::find(iset.begin(), iset.end(), 7);
    if (ite != iset.end())
    {
        std::cout << "found " << *ite << std::endl;
    }

    ite = iset.find(5);
    if (ite != iset.end())
    {
        std::cout << "found " << *ite << std::endl;
    }
    //can not modify value by iterator, not allowed, values is ordered in RB-tree.
    //*ite = 9;
}