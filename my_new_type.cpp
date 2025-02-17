#include <iostream>

class MyNewType
{
    friend std::ostream &operator<<(std::ostream &os, const MyNewType &r);
    friend MyNewType operator+(const MyNewType &r1, const MyNewType &r2);

private:
    int attr1{0};
    int attr2{0};
    //manipuler les objets et les autres méthodes
    void method1()
    {
        std::cout << "method1" << std::endl;
    }

public: //ce que l'utilisateur peut utiliser pour faire ses programmes
    MyNewType() = default; //on remet le constructeur par défaut (on l'avait redéfini)
    explicit MyNewType(int attr) : attr1{attr}, attr2{attr} //jamais il ne pourra être utilisé implicitement par C++
    {
        std::cout << "constructeur avec un seul argument" << std::endl;
    }

}