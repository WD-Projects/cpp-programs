/*
Virtual function: A virtual function is a member function that you expect to be redefined in derived class.
    1. virtual functions are dynamic in nature
    2. defined by keyword "virtual" inside a base class and are always declared with a base class and overriden in a child class
    3. A virtual function is called during runtime
*/
#include <iostream>
#include <string>
using namespace std;
class Parent {
public:
    void getInfo() {
        cout << "parent" << endl;
    }

    virtual void hellow() {
        cout << "hellow i am virtual function from parent" << endl;
    }
};

class Child : public Parent {
public:
    void getInfo() {
        cout << "child" << endl;
    }

    void hellow() {
        cout << "hellow i am virtual function from child" << endl;
    }
};

int main() {
    Child c1;
    c1.hellow();
}