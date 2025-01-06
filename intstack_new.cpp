#include <iostream>
#include <stdexcept>
#include <stack>

// on définit un type de donnée (une classe) pour gérer une pile d'entier de taille 12 (SIZE)
class IntStack
{
private:
    // vos attributs pour représenter la pile d'entier
    // dans cette version toutes les piles sont de taille SIZE
    int nb; // nombre d'éléments dans ma pile
    int size;
    int *tab;
    int tab[12];

public:
    //constructeur
    IntStack(int taille_initiale = 10) : size(taille_initiale), nb(0){
        if (taille_initiale <= 0){
            throw std::invalid_argument("La capacité initiale doit être positive");
        }
        tab = new int[size];
    }
            
        // toute la place allouée est détruite quand on sort du constructeur sauf si y'a new -> c'est nous qui gérons la place allouée et elle est détruite que quand on lui dit
        // constructeur : doit contenir new
    
    //destructeur
    ~IntStack(){
        delete [] tab;
    }

    //constructeur de copie
    IntStack (const IntStack& autre) {
        tab = new int[size];  //nouveau tableau
        for (int i = 0; i < size; ++i) {
            tab[i] = autre.tab[i];  //copie des éléments
        }
    }

    //operateur d'affectation
    IntStack operator=(const IntStack& autre){
        size = autre.size;
        nb = autre.nb;
        tab = new int[size];
        for (int i = 0; i < size; ++i){
            tab[i] = autre.tab[i];
        }
    }

    bool is_empty()
    {
        // cette fonction teste si la pile est vide
        if (nb == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool is_full()
    {
        // cette fonction teste si la pile est pleine
        if (nb == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(int e)
    {
        // cette fonction ajoute l'entier e dans la pile
        //  push(int e)stores e at the top of the stack if the stack is not full
        if (is_full())
        {
            exit(0);
        }
        else
        {
            tab[nb] = e;
            nb = nb + 1;
        }
    }

    int get_top()
    {
        // cette fonction retourne le dernier entier empilé
        // get_pop() returns the element on top of the stack if the stack is not empty
        if (is_empty())
        {
            exit(0);
        }
        else
        {
            int a;
            a = tab[nb - 1];
            return a;
        }
    }

    int pop()
    {
        // cette fonction retourne le dernier entier empilé
        // et supprime cet entier de la pile if the stack is not empty
        if (is_empty())
        {
            exit(0);
        }
        else
        {
            int a;
            a = tab[nb - 1];
            nb = nb - 1;
            return a;
        }
    }

    void print()
    {
        // cette fonction affiche la pile, par exemple
        // [1 2 3 [ pour dire que 3 entiers sont dans la pile
        // le dernier empilé est 3
        std::cout << "[";
        for (int i = 0; i < nb; i++)
        {
            std::cout << tab[i] << " ";
        }
        std::cout << "] ";
    }
};

// 1. réaliser le code pour faire fonctionner cette pile d'entier de taille fixée à la compilation
// 2. quelles sont les méthodes qui ne modifient pas l'objet sur lequel elles sont appelées
//    faites en sorte qu'elles puissent être appelées sur un objet constant
// 3. faites la fonction qui permet d'afficher un objet de type IntStack directement avec <<<
//    std::cout << s1;
//    il faut redéfinir l'operator<< en appelant la méthode print

int main()
{
    IntStack i(10);
    IntStack j(i);
    j=i;
    j.operator=(i);
}
