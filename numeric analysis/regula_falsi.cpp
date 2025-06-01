#include <iostream>
#include <cmath>
#include <iomanip> // this is called for alignment
using namespace std;
double f(double x)
{
    return 3 * x - cos(x) - 1; // Example: f(x) = 3x - cosx - 1
}
double regula_falsi_method(double a, double b)
{
    double c; // this is the root
    if (f(a) * f(b) > 0) // condition for working regula falsi method
    {
        cout << "Regula falsi method cannot be applied";
        return NAN; // NAN means not a number
    }
    cout << "Root finding with regula falsi method : " << endl;
    // align the values
    cout << setw(15) << "a" << setw(15) << "b" << setw(15) << "f(a)" << setw(15) << "f(b)" << setw(15) << "c" << setw(15) << "f(c)" << endl;
    while (abs(f(c)) >= 0.0001) // this means, the loop will false when the approximate root c will be found
    {
        c = ((a * f(b)) - (b * f(a))) / (f(b) - f(a)); // formula for finding root in regula falsi method
        // interchanging the values
        if (f(a) * f(c) <= 0){
            b = c;
        }
        else{
            a = c;
        }
        //just align the values
        cout << setw(15) << fixed << setprecision(6) << a << setw(15) << b << setw(15) << f(a) << setw(15) << f(b) << setw(15) << c << setw(15) << f(c) << endl;
    }
    return c; 
}
int main()
{
    double a, b;
    cout << "Enter the two range of the root [a,b] : " << endl;
    cin >> a >> b;
    double result = regula_falsi_method(a, b); // calling the function for regula falsi
    cout << "The approximate root is : " << result << endl; // printing the result
}