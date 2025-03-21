
#include <iostream>

class Integer {
private:
    int value;  

public:  
    //constructeur par défaut
    Integer() : value(0) {}

    //constructeur avec paramètre
    Integer(int v) : value(v) {}

    //copie
    Integer(const Integer& other) : value(other.value) {}

    //affectation
    Integer& operator=(const Integer& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    //incrémenter la valeur
    void incr() {
        value += 1;
    }

    //afficher la valeur
    void print() const {
        std::cout << "Valeur : " << value << std::endl;
    }
};
