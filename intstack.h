#include <iostream>
#include <stdexcept>

// constante entière pour la taille de la pile
const int SIZE(12);

// Classe pour gérer une pile d'entiers de taille fixe
class IntStack
{
private:
    int tab[SIZE];   // tableau pour stocker les éléments de la pile
    int elem = 0;    // nombre d'éléments dans la pile
    int size = SIZE; // taille maximale de la pile

public:
    // Vérifie si la pile est vide
    bool is_empty() const
    {
        return elem == 0;
    }

    // Vérifie si la pile est pleine
    bool is_full() const
    {
        return elem == size;
    }

    // Ajoute un élément à la pile
    void push(int e)
    {
        if (is_full())
        {
            throw std::overflow_error("La pile est pleine.");
        }
        tab[elem++] = e;
    }

    // Retourne l'élément en haut de la pile sans le supprimer
    int get_top() const
    {
        if (is_empty())
        {
            throw std::underflow_error("La pile est vide.");
        }
        return tab[elem - 1];
    }

    // Supprime et retourne l'élément en haut de la pile
    int pop()
    {
        if (is_empty())
        {
            throw std::underflow_error("La pile est vide.");
        }
        return tab[--elem];
    }

    // Affiche le contenu de la pile
    void print() const
    {
        std::cout << "[";
        for (int i = 0; i < elem; ++i)
        {
            std::cout << tab[i] << " ";
        }
        std::cout << "]";
    }

    // Redéfinition de l'opérateur << pour afficher la pile
    friend std::ostream& operator<<(std::ostream& os, const IntStack& stack)
    {
        stack.print();
        return os;
    }
};

