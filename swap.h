#include <iostream>

inline void swap(int* pa, int* pb) {
    int t = (*pa);
    *pa = *pb;
    *pb = t;
}

inline void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

