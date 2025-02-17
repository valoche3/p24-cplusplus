#include <iostream>
#include <stdexcept>
#include <stack>


class IntStack
{
    int n; // nombre d'éléments dans ma pile
    int size; // taille de la pile
    int *tab;

public:
    IntStack(int s);
    IntStack(const IntStack &r);
    IntStack &operator = (const IntStack &r)
    {
        if (this != &r)
        { // éviter les calculs inutiles
            size = r.size;
            n = r.n;
            delete[] tab; // on supprime toutes les données de l'objet à qui on assigne r
            tab = new int[size];
            for (int i = 0; i < n; ++i)
            {
                tab[i] = r.tab[i];
            }
        }
        return *this;
    };
    ~IntStack();
    bool is_empty();
    bool is_full();
    void push(int e);
    int get_top();
    int pop();
    void print();
};