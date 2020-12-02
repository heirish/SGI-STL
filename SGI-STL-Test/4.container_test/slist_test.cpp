#include <iostream>
#include <forward_list>
#include <algorithm>
template <typename T>
void DisplayIteratorable(const T &iteratorable)
{
    for (const auto &item : iteratorable)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int i;
    std::forward_list<int> islist;
    std::cout << "is empty" << islist.empty()
              << ",max_size:" << islist.max_size() << std::endl;

    islist.push_front(9);
    islist.push_front(1);
    islist.push_front(2);
    islist.push_front(3);
    islist.push_front(4);
    std::cout << "is empty" << islist.empty()
              << ",max_size:" << islist.max_size() << std::endl;
    DisplayIteratorable(islist);

    std::forward_list<int>::iterator iter = std::find(islist.begin(), islist.end(), 1);
    if (iter != islist.end())
    {
        islist.insert_after(iter, 99);
    }
    std::cout << "after insert after 99" << std::endl;
    DisplayIteratorable(islist);

    iter = std::find(islist.begin(), islist.end(), 3);
    if (iter != islist.end())
    {
        islist.erase_after(iter);
    }
    std::cout << "after erase after 3" << std::endl;
    DisplayIteratorable(islist);
}