#include <cstddef>
#include <iostream>
int fcmp(const void* elem1, const void* elem2);

int main() {
    int ia[6] = {7,2,4,9,5,1};
    for(int i=0; i<6; i++) {
        std::cout << ia[i] << " ";
    }
    std::cout << std::endl;

    qsort(ia, sizeof(ia)/sizeof(int), sizeof(int), fcmp);
    for(int i=0; i<6; i++) {
        std::cout <<ia[i] << " ";
    }
    std::cout << std::endl;
}

int fcmp(const void* elem1, const void* elem2) {
    const int* i1 = reinterpret_cast<const int*>(elem1);
    const int* i2 = reinterpret_cast<const int*>(elem2);
    if (*i1 < *i2) {
        return -1;
    } else if(*i1 == *i2) {
        return 0;
    } else {
        return 1;
    }
}