# include <iostream>

void swap(int* pa, int* pb) {
    int t = (*pa);
    *pa = *pb;
    *pb = t;
}

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a = 82;
    int b = -72;
    int* pa = &a;
    int* pb = &b; 
    std::cout << "Avant le swap avec les pointeurs : a = " << a << ", b = " << b << std::endl;
    swap(pa, pb);
    std::cout << "Après le swap avec les pointeurs : a = " << a << ", b = " << b << std::endl;
    std::cout << "Avant le swap avec les références : a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "Après le swap avec les références : a = " << a << ", b = " << b << std::endl;
    return 0;
}

