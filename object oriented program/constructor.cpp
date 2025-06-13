/*
copy constructor: special constructor (default) used to copy properties of one object to another.

there are two types of copy constructor:
1. default copy costructor 
2. custom or user defined copy constructor

Constructor: special methods invoked autometically at the time of object creation. used for initialisation.

key points:

1. same name as class(i.e if we decleare the class name as "class Teacher" the constructor name will be Teacher).

2. constructor doesn't have a reutrn type.

3. only called once(autometically) at object creation.

4. memory allocation happens when constructor is called(constructor doesn't created for classes it created for objects. when a class is created few amount of memory will be allocated but when an object is created the memory allocation will be happened and the memory will be allocated for  objects when the constructor is called. it can be called by default with compiler constructor or with user defined constructor).

5. constructor should be must called inside public access modifier. 


6. constructor will be called at first for each object declearation.

7. contructor overloading(when multiple constructors are available inside a single class) is a example of polymorphisom.

8. Contructor will be called for each object everytime at first.
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

    // constructor(this line will print at frist and will be printed for 2 times because here is 2 objects t1 & t2)
    /* output: hi, i am costructor
               hi, i am costructor
               mahir
               23000
               akib */ 
    Teacher(){
        cout << "hi, i am costructor" << endl;
    }

    // when constructor is called the dept will be assigned
    // non_perameterized
    Teacher(){
        dept = "computer science";
    }

    // peramiterized constructor
    Teacher(string n, string d, string s, double sal){
        name = n;
        dept = d;
        subject = s;
        salary = sal;
    }
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

    void getinfo(){
        cout << "name: " << name << endl;
        cout << "subject: " << subject << endl;
    }
};

int main(){
    // Teacher t1, t2;// constructor called autometically
    // t1.name = "mahir";
    // t2.name = "akib";
    // t1.setSalary(23000);

    // cout << t1.name << endl;
    // cout << t1.getSalary() << endl;
    // cout << t2.name << endl;
    // cout << t2.dept << endl;
    Teacher t1("mahir", "cse", "c++", 23000);
    t1.getinfo();
    return 0;
} 
