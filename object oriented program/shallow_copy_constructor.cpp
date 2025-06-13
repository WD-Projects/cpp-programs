/*
Shallow copy constructor: a shallow copy of an object copies all of the member values from one object ot another. but it creates problem when the memory is dynamically allocated. compiler can create shallow constructor by default.
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

    // shallow copy
    Student(Student &originalObject) {
        this->name = originalObject.name;
        this->cgpaptr = originalObject.cgpaptr;
    }

    void getInfo() {
        cout << "name: " << name << endl;
        cout << "cgpa: " << *cgpaptr << endl;
    }
};
int main() {
    Student s1("mahir", 4.0);
    s1.getInfo(); // cgpa will 4.0 for s1
    Student s2(s1);
    *(s2.cgpaptr) = 3.5;
    s1.getInfo(); // cgpa will 3.5 for s1

    /* here the problem is in dynamic memory allocation when we change the cgpa of s2, the s1 cgpa has been autometically changed because of shallow constructor and this is the problem of shallow constructor during dynamic memory allocation */
}