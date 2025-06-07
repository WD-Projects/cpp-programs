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
};

int main(){
    Teacher t1;// constructor called autometically
    t1.name = "mahir";
    t1.setSalary(23000);

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;
    return 0;
} 
