#include "intstack_new.h"
#include <iostream>

//vérifie si la pile est vide
bool IntStack::is_empty() const
{
    return elem == 0;
}

//vérifie si la pile est pleine
bool IntStack::is_full() const
{
    return elem == size;
}

//ajoute un élément à la pile
void IntStack::push(int e)
{
    if (is_full())
    {
        throw std::overflow_error("La pile est pleine.");
    }
    tab[elem++] = e;
}

//retourne l'élément en haut de la pile sans le supprimer
int IntStack::get_top() const
{
    if (is_empty())
    {
        throw std::underflow_error("La pile est vide.");
    }
    return tab[elem - 1];
}

//supprime et retourne l'élément en haut de la pile
int IntStack::pop()
{
    if (is_empty())
    {
        throw std::underflow_error("La pile est vide.");
    }
    return tab[--elem];
}

//affiche le contenu de la pile
void IntStack::print() const
{
    std::cout << "[";
    for (int i = 0; i < elem; ++i)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << "]";
}

//redéfinition de l'opérateur << pour afficher la pile
std::ostream& operator<<(std::ostream& os, const IntStack& stack)
{
    stack.print();
    return os;
}

//programme principal
int main()
{
    try
    {
        IntStack s1;
        s1.print(); // Affichera : []
        std::cout << std::endl;

        s1.push(1);
        s1.push(2);
        s1.push(3);
        s1.print(); // Affichera : [1 2 3 ]
        std::cout << std::endl;

        std::cout << s1.pop() << std::endl; // Affichera : 3
        s1.print(); // Affichera : [1 2 ]
        std::cout << std::endl;

        std::cout << s1 << std::endl; // Utilisation de l'opérateur <<
    }
    catch (const std::exception& e)
    {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}
