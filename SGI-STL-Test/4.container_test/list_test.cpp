#include <list>
#include <iostream>
#include <algorithm>

void printList(const std::list<int>& ilist) {
    std::list<int>::const_iterator it = ilist.begin();
    for (; it != ilist.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
int main()

{
    int i;
    std::list<int> ilist;
    std::cout << "size=" << ilist.size() << std::endl;

    ilist.push_back(0);
    ilist.push_back(1);
    ilist.push_back(2);
    ilist.push_back(3);
    ilist.push_back(4);
    std::cout << "size=" << ilist.size() << std::endl;

    printList(ilist);
    std::cout << std::endl;

    std::list<int>::iterator it = std::find(ilist.begin(), ilist.end(), 1);
    if (it != ilist.end()) {
        ilist.insert(it, 99);
    }
    printList(ilist);
    std::cout << "size=" << ilist.size() << std::endl;
    std::cout << "*it=" << *it << std::endl;

    it = std::find(ilist.begin(), ilist.end(), 3);
    if (it != ilist.end()) {
        ilist.erase(it);
    }
    printList(ilist);
    std::cout << "size=" << ilist.size() << std::endl;
    //bug, after erase, it is undefined. value is not right.
    std::cout << "*it=" << *it << std::endl;
}