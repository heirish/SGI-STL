#include <deque>
#include <iostream>
#include <algorithm>

void Display(const std::deque<int>& ideq) {
    std::deque<int>::const_iterator it = ideq.begin();
    for(; it != ideq.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::deque<int> ideq(20, 9);
    std::cout << "size=" << ideq.size() << std::endl;

    for(int i=0; i<ideq.size(); i++) {
        ideq[i] = i;
    }
    Display(ideq);

    for(int i=0; i<3; i++) {
        ideq.push_back(i);
    }
    Display(ideq);

    ideq.push_front(99);
    ideq.push_front(98);
    ideq.push_front(97);
    Display(ideq);

    std::deque<int>::iterator it = std::find(ideq.begin(), ideq.end(), 99);
    if (it != ideq.end()) {
        std::cout << *it << std::endl;
        std::cout << *(it._M_cur) << std::endl;
    }
}