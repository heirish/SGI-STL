#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <assert.h>

//void DisplayIteratorable(const std::vector<int> &ivec)
template <typename T>
void DisplayIteratorable(const T &iteratorable)
{
    std::cout << "size=" << iteratorable.size() << std::endl;
    for (const auto &item : iteratorable)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
void DisplayArray(const int *array, size_t size)
{
    assert(size >= 0);
    assert(array);
    std::cout << "size=" << size << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << *(array + i) << " ";
    }
    std::cout << std::endl;
}
int main()
{
    //heap by vector
    {
        int ia[9] = {0, 1, 2, 3, 4, 8, 9, 3, 5};
        //std::vector<int> ivec(ia, ia + 9);
        std::deque<int> ivec(ia, ia + 9);
        DisplayIteratorable(ivec);

        std::make_heap(ivec.begin(), ivec.end());
        DisplayIteratorable(ivec);

        //need first push value to vector end
        ivec.push_back(7);
        std::push_heap(ivec.begin(), ivec.end());
        DisplayIteratorable(ivec);

        //pop_heap only move max node to vector end, not remove it. must call pop_back manually
        std::pop_heap(ivec.begin(), ivec.end());
        std::cout << "now back:" << ivec.back() << std::endl;
        ivec.pop_back();

        //sort ascend
        std::sort_heap(ivec.begin(), ivec.end());
        DisplayIteratorable(ivec);
    }

    //heap by array
    {
        int ia[9] = {0, 1, 2, 3, 4, 8, 9, 3, 5};
        DisplayArray(ia, sizeof(ia) / sizeof(int));

        std::make_heap(ia, ia + 9);
        std::cout << "after make_heap array:" << std::endl;
        DisplayArray(ia, sizeof(ia) / sizeof(int));

        std::sort_heap(ia, ia + 9);
        std::cout << "after sort_heap array:" << std::endl;
        DisplayArray(ia, sizeof(ia) / sizeof(int));

        //经过排序过后的heap不再是一个合法的heap
        //重新再make
        std::make_heap(ia, ia + 9);
        DisplayArray(ia, sizeof(ia) / sizeof(int));
        std::pop_heap(ia, ia + 9);
        std::cout << "after pop, last one:" << ia[8] << std::endl;
    }
}