/*
Abstruction: hiding all unnecessary details and showing only the important parts.

There is an another way to do abstruction by using abstruction classes:
    1. Abstruct classes are used to provide a base class form which other classes cna be derived (it means abstruct classes are blueprints for ther classes).
    2. They cannot be instantiated (abstruct class cannot create object) and are meant to be inherited.
    3. Abstruct classes are typically used to define an interface for derived classes.
*/
#include <iostream>
#include <string>
using namespace std;
// abstruct class
class Shape {
    virtual void draw() = 0; // pure virtual function
};

class Circle : public Shape {
public:
    void draw() {
        cout << "drawing a circle" << endl;
    }
};

int main() {
    Circle c1;
    c1.draw();
}