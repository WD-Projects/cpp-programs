#include <iostream>
#include <string>
using namespace std;
class Teacher {
private:
    double salary;
public:
    string name;
    string dept;
    string subject;

    Teacher(string name, string dept, string subject, double salary){
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = salary;
    }
    void getinfo(){
        cout << "name: " << name << endl;
        cout << "subject: " << subject << endl;
    }
};
int main(){
    Teacher t1("mahir", "cse", "c++", 25000);
    Teacher t2(t1); // default copy constructor
    t2.getinfo();
}