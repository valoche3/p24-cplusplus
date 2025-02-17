#include <iostream>
#include <vector>

class Form
{
private:
    int abscisse;
    int ordonnee;

public:
    Form(int x, int y) : abscisse(x), ordonnee(y) // protected : j'ai le droit, les classes dérivées ont le droit, sinon personne d'autres
    {
    }

    Form *find(int x, int y, std::vector<Form *> &v) // s = une adresse
    {
        for (auto s : v)
        { // auto : détermine moi automatiquement le type
            if (s->is_at_position(x, y))
            {
                return s; // find renvoie l'adresse de cet objet
            }
        }
        return nullptr; // pointeur vide
    }

    void move(int new_x, int new_y)
    {
        abscisse = new_x;
        ordonnee = new_y;
    }

    virtual double surface()
    {
        return -99.9; // il ne faut pas mettre égal à 0, sinon ça veut dire qu'on ne peut pas construire une Form
    }

    virtual bool is_at_position(int x, int y)
    {
        return ((abscisse > x - 2 && abscisse < x + 2) && (ordonnee > y - 2 && ordonnee < y + 2));
    }

}; // obligatoire

class Square : public Form
{
    int side;

public:
    Square(int x, int y, int n) : side(n), Form(x, y) {
                                  };
    virtual double surface()
    {
        return side * side;
    };
};

class Rectangle : public Form
{
    int width;
    int height;

public:
    Rectangle(int x, int y, int a, int b) : width(a), height(b), Form(x, y) {
                                            };

    virtual double surface()
    {
        return width * height;
    }
};

class Circle : public Form
{
    int radius;

public:
    Circle(int x, int y, int r) : radius(r), Form(x, y) {
                                  };

    virtual double surface() override // pour préciser que la fonction est héritée du dessus
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    Circle c(10, 20, 4);
    Form *ps = &c;   // type moins défini : adresse d'un shape (upcasting)
    ps->surface();   // l'adresse permet de retrouver le bon area, celui de Form ici
    Circle *pc = &c; // type exact
    pc->surface();   // il prend celui de Circle ici
    Rectangle r(20, 30, 30, 60);
    // std:: = namespace
    std::vector<Form *> v; // il prend une adresse en argument, il crée des espaces vides du type Form
    // si on met pas l'étoile, il nous coupe tout ce qui ne fait pas partie de Form
    // si on met l'étoile, on prend les adresses et il a bien tous les éléments
    v.push_back(&c); // on lui donne l'adresse
    v.push_back(&r);
    s = find(20, 30, &v); //renvoie la première forme qu'elle voit à la position (2,3)
    s.surface();
    v[0]->move(4, 6);
    v[1]->move(2, 8);
    std::cout << v[0]->surface() << std::endl;
    std::cout << v[1]->surface() << std::endl;
    return 0;
}