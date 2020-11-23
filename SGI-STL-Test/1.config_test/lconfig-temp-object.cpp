#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
class print{
    public:
    void operator()(const T& item) {
        std::cout << item << " ";
    }
};

int main() {
    int ia[6] = {1,2,3,4,5,6};

    std::vector<int> iv(ia, ia+6);
    for_each(iv.begin(), iv.end(), print<int>());
}
