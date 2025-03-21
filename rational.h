#include <iostream>
#include <numeric>

class Rational {
    friend Rational operator+(const Rational&, const Rational&);
    friend Rational operator-(const Rational&, const Rational&);
    friend Rational operator*(const Rational&, const Rational&);
    friend Rational operator/(const Rational&, const Rational&);
    friend std::ostream& operator<<(std::ostream&, const Rational&);

private:
    int num;
    int denom;

    void reduce(); //réduction de la fraction

public:
    //constructeur avec vérification du dénominateur
    Rational(int n = 0, int d = 1);

    //conversion en float
    operator float() const;

    //affichage
    void print() const;
    
    //évaluation (division entière)
    void eval() const;

    int getNum() const { return num; }
    int getDenom() const { return denom; }
};
