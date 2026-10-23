#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape {
protected:
    string name;
public:
    Shape(string n) : name(n) {}
    virtual double area() const { return 0.0; }        
    virtual void draw() const { cout << "Drawing a generic shape\n"; }
    string getName() const { return name; }
    virtual ~Shape() {}                                  
};

class Circle : public Shape {
    double r;
public:
    Circle(double r) : Shape("Circle"), r(r) {}
    double area() const override { return M_PI * r * r; }
    void draw() const override { cout << "Drawing a circle with radius " << r << "\n"; }
};

class Rectangle : public Shape {
    double w, h;
public:
    Rectangle(double w, double h) : Shape("Rectangle"), w(w), h(h) {}
    double area() const override { return w * h; }
    void draw() const override { cout << "Drawing a rectangle " << w << " x " << h << "\n"; }
};

class Triangle : public Shape {
    double b, h;
public:
    Triangle(double b, double h) : Shape("Triangle"), b(b), h(h) {}
    double area() const override { return 0.5 * b * h; }
    void draw() const override { cout << "Drawing a triangle with base " << b << " and height " << h << "\n"; }
};

void describe(const Shape& s) {
    s.draw();
    cout << "  " << s.getName() << " area = " << s.area() << "\n";
}

int main() {
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(3, 8);

    cout << "--- Through base-class pointers ---\n";
    Shape* shapes[] = { &c, &r, &t };
    for (Shape* p : shapes) {
        p->draw();   
        cout << "  " << p->getName() << " area = " << p->area() << "\n";
    }

    cout << "\n--- Through base-class reference ---\n";
    describe(c);
    describe(r);
    describe(t);
    return 0;
}
