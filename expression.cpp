#include <iostream>
#include <limits>

int main(){
    std::cout <<std::numeric_limits<unsigned int>::max() 
        << std::endl;
    std::cout <<std::numeric_limits<unsigned int>::max() + 1 
        << std::endl; //overflow
    return 0;
}