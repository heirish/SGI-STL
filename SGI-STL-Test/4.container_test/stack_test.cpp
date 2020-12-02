#include <stack>
#include <list>
#include <vector>
#include <deque>
#include <iostream>

int main() {
    // following containers can be used as stack's base container
    //std::stack<int, std::list<int>> istack;
    //std::stack<int, std::vector<int>> istack;
    std::stack<int, std::deque<int>> istack;
    istack.push(3);
    istack.push(5);
    istack.push(8);
    istack.push(1);

    std::cout << "size=" << istack.size() <<std::endl;
    std::cout << istack.top() << std::endl;

    istack.pop(); 
    std::cout << istack.top() << std::endl;
    istack.pop(); 
    std::cout << istack.top() << std::endl;
    istack.pop(); 
    std::cout << istack.top() << std::endl;
    std::cout << "size=" << istack.size() << std::endl;
}