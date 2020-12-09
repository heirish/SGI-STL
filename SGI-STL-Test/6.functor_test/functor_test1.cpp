#include <functional>
#include <iostream>

int main()
{
    std::equal_to<int> equalobj;
    std::not_equal_to<int> notequalobj;
    std::greater<int> greaterobj;
    std::greater_equal<int> greatoerequalobj;
    std::less<int> lessobj;
    std::less_equal<int> lessequalobj;

    std::cout << equalobj(3, 5) << std::endl;
    std::cout << notequalobj(3, 5) << std::endl;
    std::cout << greaterobj(3, 5) << std::endl;
    std::cout << greatoerequalobj(3, 5) << std::endl;
    std::cout << lessobj(3, 5) << std::endl;
    std::cout << lessequalobj(3, 5) << std::endl;

    std::cout << std::equal_to<int>()(3, 5) << std::endl;
    std::cout << std::not_equal_to<int>()(3, 5) << std::endl;
    std::cout << std::greater<int>()(3, 5) << std::endl;
    std::cout << std::greater_equal<int>()(3, 5) << std::endl;
    std::cout << std::less<int>()(3, 5) << std::endl;
    std::cout << std::less_equal<int>()(3, 5) << std::endl;
}