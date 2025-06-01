#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
// function to find the root of
double f(double x) {
    return 3 * x - cos(x) - 1; // Example: f(x) = 3x - cosx - 1
}
// secant method
void secantMethod(double x0, double x1) {
    cout << setw(10) << "x0" << setw(10) << "x1" << setw(10) << "c" << setw(15) << "func(c)" << endl;
    double c; // this is the root
    while (abs(x1 - x0) >= 0.01) {
        // secant formula
        c = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0)); // formula for finding root
        cout << fixed << setprecision(4) << setw(10) << x0 << setw(10) << x1 << setw(10) << c << setw(15) << f(c) << endl;
        // update x0 and x1
        x0 = x1;
        x1 = c;
    }
    cout << "The value of root is: " << c << endl; // printing the value of root
}
int main() {
    double x0, x1; 
    cout << "Enter the value for x0 and x1 : " << endl;
    cin >> x0 >> x1;
    secantMethod(x0, x1); // calling the function 
}