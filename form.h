#include <vector>

class Form {
private:
    int abscisse;
    int ordonnee;

public:
    Form(int x, int y);
    Form* find(int x, int y, std::vector<Form*>& v);
    void move(int new_x, int new_y);
    virtual double surface();
    virtual bool is_at_position(int x, int y);
    virtual ~Form() = default;  //destructeur virtuel 
};

//classe dérivée Square
class Square : public Form {
private:
    int side;

public:
    Square(int x, int y, int n);
    virtual double surface() override;
};

//classe dérivée Rectangle
class Rectangle : public Form {
private:
    int width;
    int height;

public:
    Rectangle(int x, int y, int a, int b);
    virtual double surface() override;
};

//classe dérivée Circle
class Circle : public Form {
private:
    int radius;

public:
    Circle(int x, int y, int r);
    virtual double surface() override;
};

