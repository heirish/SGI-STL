#include <queue>
#include <iostream>
#include <algorithm>


int main() {
    int ia[9] = {0,1,2,3,4,8,9,3,5};
    std::priority_queue<int> ipq(ia, ia+9);
    std::cout << "size=" << ipq.size() << std::endl;
    std::cout << "top=" << ipq.top() << std::endl;

    while(!ipq.empty()) {
        std::cout << ipq.top() << " ";
        ipq.pop();
    }

    std::cout << std::endl;
}