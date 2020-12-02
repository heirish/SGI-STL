#include <deque>
#include <list>
#include <queue>
#include <iostream>

int main() {
    //std::queue<int, std::list<int>> iqueue;
    std::queue<int, std::deque<int>> iqueue;
    iqueue.push(4);
    iqueue.push(9);
    iqueue.push(2);
    iqueue.push(7);
    iqueue.push(1);
    std::cout << "size=" << iqueue.size() << std::endl;

    std::cout << iqueue.front() << std::endl;
    iqueue.pop();
    std::cout << iqueue.front() << std::endl;
    iqueue.pop();
    std::cout << iqueue.front() << std::endl;
    iqueue.pop();
    std::cout << iqueue.front() << std::endl;
    iqueue.pop();
    std::cout << iqueue.front() << std::endl;
    iqueue.pop();
    std::cout << "size=" << iqueue.size() << std::endl;
}