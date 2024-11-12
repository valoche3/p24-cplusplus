#include <iostream>

int add (int a, int b);
extern int i;

int main(int argc, char* argv[]) {
    std::cout << add(i, 90) << std::endl;
    return 0;
    //return EXIT_SUCCESS;
}

int i = 12; 

int add (int i, int j) {
    return i+j;
}