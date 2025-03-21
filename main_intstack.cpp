#include <iostream>
#include "intstack.h"

int main()
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
    return 0;
}
