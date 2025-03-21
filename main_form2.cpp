#include "form.h"
#include <iostream>
#include <cmath> 

//implémentation de la classe
Form::Form(int x, int y) : abscisse(x), ordonnee(y) {}

Form* Form::find(int x, int y, std::vector<Form*>& v) {
    for (auto s : v) {
        if (s->is_at_position(x, y)) {
            return s;
        }
    }
    return nullptr;
}

void Form::move(int new_x, int new_y) {
    abscisse = new_x;
    ordonnee = new_y;
}

double Form::surface() {
    return -99.9; //valeur par défaut
}

bool Form::is_at_position(int x, int y) {
    return ((abscisse > x - 2 && abscisse < x + 2) && (ordonnee > y - 2 && ordonnee < y + 2));
}

//implémentation de la classe Square
Square::Square(int x, int y, int n) : side(n), Form(x, y) {}

double Square::surface() {
    return side * side;
}

//implémentation de la classe Rectangle
Rectangle::Rectangle(int x, int y, int a, int b) : width(a), height(b), Form(x, y) {}

double Rectangle::surface() {
    return width * height;
}

//implémentation de la classe Circle
Circle::Circle(int x, int y, int r) : radius(r), Form(x, y) {}

double Circle::surface() {
    return M_PI * radius * radius; // Utilisation de la constante M_PI pour une meilleure précision
}

int main() {
    Circle c(10, 20, 4);
    Form* ps = &c;   
    ps->surface();  
    Circle* pc = &c; 
    pc->surface();  

    Rectangle r(20, 30, 30, 60);
    std::vector<Form*> v;
    v.push_back(&c); //on lui donne l'adresse de l'objet
    v.push_back(&r);

    Form* s = ps->find(20, 30, v); //recherche une forme à la position donnée
    if (s != nullptr) {
        std::cout << s->surface() << std::endl;
    }

    v[0]->move(4, 6);
    v[1]->move(2, 8);

    std::cout << "Surface de la forme 1 (Circle): " << v[0]->surface() << std::endl;
    std::cout << "Surface de la forme 2 (Rectangle): " << v[1]->surface() << std::endl;

    return 0;
}
