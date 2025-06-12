#include <iostream>
#include <string>
using namespace std;
class person {
public:
    string name;
    int age;

    person(string name, int age) {
        cout << "i am parent class constructor" << endl;
        this->name = name;
        this->age = age;
    }
};

class student : public person {
public:
    int rollno;

    // with this syntex "person(name, age)" the person (parent) constructor is called by student  
    student(string name, int age, int rollno) : person(name, age) {
        cout << "i am child class constructor" << endl;
        this->rollno = rollno;
    }

    void getinfo() {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "rollno: " << rollno << endl;
    }
};

int main() {
    student s1("Akib Hossain Mahir", 23, 193);
    s1.getinfo();
}
