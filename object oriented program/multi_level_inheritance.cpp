#include <iostream>
#include <string>
using namespace std;
class Person {
public:
    string name;
    int age;

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

class Student : public Person {
public:
    int rollno;

    Student(string name, int age, int rollno) : Person(name, age) {
        this->rollno = rollno;
    }
};

class GraduateStudent : public Student {
public:
    string research_area;

    GraduateStudent(string name, int age, int rollno, string research_area) : Student(name, age, rollno) {
        this->research_area = research_area;
    }

    void getInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << rollno << endl;
        cout << "Research Area: " << research_area << endl;
    }
};

int main() {
    GraduateStudent g1("Akib Hossain Mahir", 23, 193, "Deep Learning");
    g1.getInfo();
    return 0;
}
