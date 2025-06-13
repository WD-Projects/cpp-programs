/*
Polymorphism: polymorphisom is the ability of objects to take on different forms or behave in different ways depending on the context in which they are used. Example: "constructor overloading".

    the word "poly" means "multiple" and "morph" means forms.

    there are two types of polymorphisom:
    1. compile time polymorphismm. Example: constructor overloading, function overloading, operator overloading.
    2. run time polymorphism (dynamic polymorphism). 
    
        Example:

        Function overriding: parent and child both contain the same function with different implementation. the parent class function is said to be overriden. the override (priority) concept is related to "Inheritance".
*/
#include <iostream>
#include <string>
using namespace std;
class Student {
public:
    string name;

    Student() {
        cout << "unperameterized" << endl;
    }

    Student(string name) {
        cout << "perameterized" << endl;
        this->name = name;
    }
};

int main() {
    // Student s1; // for this the umperameterized will be called 
    Student s1("Akib Hossain Mahir"); // for this perameterized constructor will be called 

    // that's how the objects is behaving in different ways depending on context. this is the concept of polymorphism
}