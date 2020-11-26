#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <iostream>


int main() {
    const int arraySize = 7;
    int ia[arraySize] = {1,2,3,4,5,6,7};

    std::vector<int> ivect(ia, ia+arraySize);
    std::list<int> ilist(ia, ia+arraySize);
    std::deque<int> ideque(ia, ia+arraySize);

    std::vector<int>::iterator it1 = std::find(ivect.begin(), ivect.end(), 4);
    if (it1 == ivect.end()) {
        std::cout << "4 not found" << std::endl;
    } else {
        std::cout << "foud " << *it1 << std::endl;
    }

    std::list<int>::iterator it2 = std::find(ilist.begin(), ilist.end(), 6);
    if (it2 == ilist.end()) {
        std::cout << "6 not found" << std::endl;
    } else {
        std::cout << "found " << *it2 << std::endl;
    }

    std::deque<int>::iterator it3 = std::find(ideque.begin(), ideque.end(), 8);
    if (it3 == ideque.end()) {
        std::cout << "8 not found" << std::endl;
    } else {
        std::cout << "found " << *it3 << std::endl;
    }
}