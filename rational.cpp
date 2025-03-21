#include "rational.h"
#include <iostream>

//constructeur avec réduction de fraction
Rational::Rational(int n, int d) : num(n), denom(d) {
    if (denom == 0) {
        throw std::invalid_argument("Le dénominateur ne peut pas être 0.");
    }
    reduce();
}

//conversion en float
Rational::operator float() const {
    return static_cast<float>(num) / static_cast<float>(denom);
}

//affichage
void Rational::print() const {
    std::cout << num << "/" << denom << std::endl;
}

//évaluation (division entière)
void Rational::eval() const {
    std::cout << num / denom << std::endl;
}

//opérateurs
Rational operator+(const Rational& r1, const Rational& r2) {
    return Rational(r1.num * r2.denom + r2.num * r1.denom, r1.denom * r2.denom);
}

Rational operator-(const Rational& r1, const Rational& r2) {
    return Rational(r1.num * r2.denom - r2.num * r1.denom, r1.denom * r2.denom);
}

Rational operator*(const Rational& r1, const Rational& r2) {
    return Rational(r1.num * r2.num, r1.denom * r2.denom);
}

Rational operator/(const Rational& r1, const Rational& r2) {
    if (r2.num == 0) {
        throw std::invalid_argument("Division par zéro impossible.");
    }
    return Rational(r1.num * r2.denom, r1.denom * r2.num);
}

//redéfinition de l'opérateur <<
std::ostream& operator<<(std::ostream& os, const Rational& r) {
    os << r.num << '/' << r.denom;
    return os;
}

int main() {
    try {
        Rational r1;
        Rational r2(1);
        Rational r3(4, 6);
        Rational r4(1, 2);
        Rational r5 = r3 + r4;
        Rational r6 = r3 - r4;
        Rational r7 = r3 * r4;
        Rational r8 = r3 / r4;

        std::cout << r3 << " + " << r4 << " = " << r5 << std::endl;
        std::cout << r3 << " - " << r4 << " = " << r6 << std::endl;
        std::cout << r3 << " * " << r4 << " = " << r7 << std::endl;
        std::cout << r3 << " / " << r4 << " = " << r8 << std::endl;

        std::cout << "Valeur float de " << r3 << " : " << static_cast<float>(r3) << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}