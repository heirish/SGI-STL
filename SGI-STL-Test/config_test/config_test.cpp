#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    #if defined(__sgi)
    std::cout << "__sgi" << std::endl;
    #endif

    #if defined(__GNUC__)
    std::cout << "__GNUC__" << std::endl;
    std::cout << __GNUC__ << " " << __GNUC_MINOR__ << std::endl;
    #endif

    
}