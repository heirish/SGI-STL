#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    int i;
    std::vector<int> iv(2, 9);
    std::cout << "size=" << iv.size() << std::endl;
    std::cout << "capacity=" << iv.capacity() << std::endl;

    iv.push_back(1);
    std::cout << "size=" << iv.size() << std::endl;
    std::cout << "capacity=" << iv.capacity() << std::endl;

    iv.push_back(2);
    std::cout << "size=" << iv.size() << std::endl;
    std::cout << "capacity=" << iv.capacity() << std::endl;

    iv.push_back(3);
    std::cout << "size=" << iv.size() << std::endl;
    std::cout << "capacity=" << iv.capacity() << std::endl;

    iv.push_back(4);
    std::cout << "size=" << iv.size() << std::endl;
    std::cout << "capacity=" << iv.capacity() << std::endl;

    for (const auto &item : iv)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    iv.push_back(5);
    std::cout << "size=" << iv.size() << std::endl;
    std::cout << "capacity=" << iv.capacity() << std::endl;

    for (const auto &item : iv)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    iv.pop_back();
    iv.pop_back();
    std::cout << "size=" << iv.size() << std::endl;
    std::cout << "capacity=" << iv.capacity() << std::endl;

    iv.pop_back();
    std::cout << "size=" << iv.size() << std::endl;
    std::cout << "capacity=" << iv.capacity() << std::endl;

    std::vector<int>::iterator it = std::find(iv.begin(), iv.end(), 1);
    if (it != iv.end())
    {
        iv.erase(it);
    }
    //erase之后的it是invalidated
    std::cout << "*it=" << *it << std::endl;
    std::cout << "size=" << iv.size() << std::endl;
    std::cout << "capacity=" << iv.capacity() << std::endl;
    for (const auto &item : iv)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    it = std::find(iv.begin(), iv.end(), 2);
    if (it != iv.end())
    {
        iv.insert(it, 3, 7);
    }
    //insert之后it的值发生了变化，而list的insert之后，it值不会发生变化
    std::cout << "*it=" << *it << std::endl;
    std::cout << "size=" << iv.size() << std::endl;
    std::cout << "capacity=" << iv.capacity() << std::endl;
    for (const auto &item : iv)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    iv.clear();
    std::cout << "size=" << iv.size() << std::endl;
    std::cout << "capacity=" << iv.capacity() << std::endl;
}