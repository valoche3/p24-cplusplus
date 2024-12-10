#include <iostream>
#include <numeric>

class Rational
{
    int denom;
    int num;

public:
    Rational(int n = 0, int d = 1) : num(n), denom(d)
    {
    }

    Rational operator+(Rational r1, Rational r2)
    {
        int num = r1.num * r2.denom + r2.num * r1.denom;
        int den = r1.denom * r2.denom;
        return Rational(num, den);
    }

    void print()
    {
        std::cout << num << "/" << denom << std::endl;
    }

    void eval()
    {
        std::cout << num / denom << std::endl;
    }

    // Rational operator+(Rational r1, Rational r2){
    //   return Rational(r1.num*r2.num)
    //}
};

// int main() {
// int i = 12;
// float pi = 3.14159;
// Rational r1;
// Rational r2(1);
// Rational r3(1, 2);
// r1.print();
// r2.print();
// r3.print()
// Rational eval(3, 4);
//}

int main()
{
    Rational r1;
    Rational r2(1);
    Rational r3(4, 6);
    Rational r4(1, 2);
    Rational r5 = r3 + r4;
    std::cout << r3 << " + " << r4 << " = " << r5 << std::endl;
    return 0;
}