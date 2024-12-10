#include <iostream>
#include <numeric>

class Rational
{
    friend Rational operator+(const Rational&, const Rational&);
    friend std::ostream &operator<<(std::ostream &os, const Rational &r);
    int denom;
    int num;

public:
    Rational(int n = 0, int d = 1) : num(n), denom(d)
    {
    }

    void print() const //fonction peut être seulement appelée sur les objets constants, le définir dans les fonctions
    {
        std::cout << num << "/" << denom << std::endl;
    }

    operator float () //transformer un rationnel en un float
    { 
        static_cast<float>(num)/static_cast<float>(denom);
    }

    void eval()
    {
        std::cout << num / denom << std::endl;
    }
};

Rational operator+(const Rational& r1, const Rational& r2) //on utilise les adresses pour éviter de recopier l'objet, const nous dit qu'on ne peut pas le modifier (juste le lire)
    {
        int num = r1.num * r2.denom + r2.num * r1.denom;
        int den = r1.denom * r2.denom;
        return Rational(num, den);
    }

std::ostream &operator<<(std::ostream &os, const Rational &r) //on redéfinit l'opérateur << pour des rationnels (que pour des int, des float et des str à la base)
{
    os << r.num << '/' << r.denom;
    return os;
}

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