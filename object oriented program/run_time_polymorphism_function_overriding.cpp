#include <iostream>
#include <string>
using namespace std;
class Parent {
public:
    void getInfo() {
        cout << "parent" << endl;
    }
};

class Child : public Parent {
public:
    void getInfo() {
        cout << "child" << endl;
    }
};

int main() {
    Child c1;
    c1.getInfo();

    // here the parent class function is overriden by child class
}