#include <vector>

class Engine
{
    int number;

public:
    Engine(int n) : number(n)
    {
    }
};

class Wheel
{
    int number;

public:
    Wheel(int n) : number(n)
    {
    }
};

class Door
{
    int number;

public:
    Door(int n) : number(n)
    {
    }
};

class Vehicle
{
    Engine e;
    Wheel w{4};
    Door d{2};
    int number;

//protected : int number;

public:
    // constructeur
    Vehicle(int n, int m) : number(n), e(m)
    { //une fois qu'on est dans le corps du constructeru Vehicle, on considère que Engine est déjà créé, donc on ne peut plus l'affecter
    }
};

class Car : public Vehicle // attention il faut un argument
{
    int color;

public: // mettre le n dans la liste d'initialisation
    Car(int n, int c) : color(c), Vehicle(n)
    {
    }

    Car(int n) : color(0), Vehicle(n)
    {
        color = 12;
        number = 27; // on peut le remettre là car protected
    }
};

int main()
{
    Vehicle v{1};
    Car c{2, 0};
    Truck t{2};
    Car *pc = &c;
    Truck *pt = &t;
    Vehicle *pv = &v;
    Vehicle *pvc = &c;
    Vehicle *pvt = &t;
    std::vector<Vehicle*>veh;
    veh.pushback(&c);
    veh[0]
}