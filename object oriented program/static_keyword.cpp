/*
Static keyword:
    static variables:
        in function, variables declares as static are created and initiated once for the lifetime of the program.
    static objects:
        static variables in a class are created and initialised once. They are shared by all the objects of the class.    
*/




// #include <iostream>
// using namespace std;
// void func() {
//     int x = 0;
//     cout << "x: " << x << endl;
//     x++;    
// }
// int main() {
//     func();
//     func();
//     func();
// }
/*
output: 
x: 0
x: 0
x: 0
*/
/* here what happens? 
    when func() is called it takes space in stack and when the function returns the value of x destroyed. so everytime the value of x reset to 0 and output is 0 everytime.
*/


// by using static keyword

#include <iostream>
using namespace std;
void func() {
    static int x = 0;
    cout << "x: " << x << endl;
    x++;
}
int main() {
    func();
    func();
    func();
}
/*
output:
x: 0
x: 1
x: 2
*/


/*
here what happens?
    when the func() is called the variable x don't take place in stack. when the func() is destroyed the variable x still remains during the lifetime of program.
*/