#include <iostream>

float pi = 3.14159;

float circle_area(int r){
    float area = pi*r*r;
    return(area);
}

int main(){
    double radius;
    std::cout<<"enter the radius of the circle : ";
    std::cin >> radius;
    double area = circle_area(radius);
    std::cout<<"the area of the circle is : " << area << std::endl;

    return 0;
}