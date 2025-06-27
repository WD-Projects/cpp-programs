/*
object oriented programming

classes & objects:
1. objects are entities on the real world.
2. class is like a blueprint of these entities.
3. by default all properties & methods are private inside the class.

access modifiers:
1. private: data & methods accessible inside the class.
2. public: data & methods accessible to everyone.
3. protected: data & methods accessible inside class & to its derived (child) class.

oops have 4 pillars:
1. Encapsulation
2. Abstruction
3. Inheritence
4. Polymorphism

Encalsulation: if we take some properties and methods under class then these properties and methods will combinely called encapsulation.
*/
#include <iostream>
#include <string>
using namespace std;
class Teacher {

// sometimes called data hiding
private:
    // now the salary is private
    double salary;

public:
    // properties/ attributes
    string name;
    string dept;
    string subject;

    // methods/ member function
    void changedept(string newdept){
        dept = newdept;
    }

    // setter(sets the values of private property)
    void setSalary(double s){
        salary = s;
    }

    //getter(returns the values of private property)
    double getSalary(){
        return salary;
    }
};

int main(){
    Teacher t1;// constructor called autometically
    t1.name = "mahir";
    t1.setSalary(23000);

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;
    return 0;
} 
