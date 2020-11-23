#include <iostream>

template <typename T>
struct plus
{
    T operator()(const T &x, const T &y)
    {
        return x + y;
    }
};

template <typename T>
struct minus
{
    T operator()(const T& x, const T& y){
        return x-y;
    }
};

int main() {
    plus<int> plusobj;
    minus<int> minusobj;

    std::cout << plusobj(2,3) << std::endl;
    std::cout << minusobj(3,2) << std::endl;

    std::cout << plus<int>()(3,4) << std::endl;
    std::cout << minus<int>()(7,2) << std::endl;
}

