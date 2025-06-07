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
