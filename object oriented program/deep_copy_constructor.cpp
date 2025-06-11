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
