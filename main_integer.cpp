#include "integer.h"

int main() {
    Integer i;     
    Integer j = i;  
    i = j;         

    i.incr();      

    //affichage
    i.print();
    j.print();

    return 0;
}
