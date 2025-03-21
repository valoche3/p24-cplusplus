#include <iostream>
#include <stdexcept>

//classe pour gérer une pile d'entiers
class IntStack
{
private:
    int* tab;     //pointeur pour stocker les éléments de la pile
    int elem = 0; //nombre d'éléments dans la pile
    int size;     //taille maximale de la pile

public:
    //vérifie si la pile est vide
    bool is_empty() const;

    //vérifie si la pile est pleine
    bool is_full() const;

    //ajoute un élément à la pile
    void push(int e);

    //retourne l'élément en haut de la pile sans le supprimer
    int get_top() const;

    //supprime et retourne l'élément en haut de la pile
    int pop();

    //affiche le contenu de la pile
    void print() const;

    //redéfinition de l'opérateur << pour afficher la pile
    friend std::ostream& operator<<(std::ostream& os, const IntStack& stack);
};
