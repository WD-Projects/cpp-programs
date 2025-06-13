/*
Destructor: destructor is opposite to constructor. constructor is mainly works for allocating memory for new created object on the other side destructor de-allocates memory. dectructor is autometically created by compiler. for example, when a program terminated the objects are autometically deleted (it's for static memory allocation not for dynamic memory allocation). destructor has the same name as class.
*/
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    double* cgpaptr;

    Student(string name, double cgpa) {
        this->name = name;
        cgpaptr = new double;
        *cgpaptr = cgpa;
    }

    // deep copy
    Student(Student &originalObject) {
        this->name = originalObject.name;
        this->cgpaptr = new double;
        *cgpaptr = *(originalObject.cgpaptr); // just copying the value
    }

    // destructor
    ~Student() {
        cout << "hi i am destructor" << endl;
        delete cgpaptr;
    }

    void getInfo() {
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaptr << endl;
    }
};

int main() {
    Student s1("mahir", 4.0);
    s1.getInfo(); 
    Student s2(s1);
    *(s2.cgpaptr) = 3.5;
    s1.getInfo(); 
    s2.getInfo();
}
