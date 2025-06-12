#include <iostream>
#include <string>
using namespace std;
class Person {
public:
    string name;
    int age;
};

class Student : public Person {
public:
    int rollno;

    void getInfo() {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "rollno: " << rollno << endl;
    }
};

int main() {
    Student s1;
    s1.name = "mahir";
    s1.age = 23;
    s1.rollno = 193;
    s1.getInfo();
}
