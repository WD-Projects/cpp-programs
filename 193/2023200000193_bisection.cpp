#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double f(double x)
{
    return 3 * x - cos(x) - 1;
}
double bisection_method(double a, double b)
{
    double c;
    if (f(a) * f(b) > 0)
    {
        cout << "Bisection method cannot be applied";
        return NAN;
    }
    cout << "Root finding with bisection method : " << endl;
    cout << setw(15) << "a" << setw(15) << "b" << setw(15) << "f(a)" << setw(15) << "f(b)" << setw(15) << "c" << setw(15) << "f(c)" << endl;
    while (abs(f(c)) >= 0.001)
    {
        c = (a + b) / 2;
        if (f(a) * f(c) <= 0){
            b = c;
        }
        else{
            a = c;
        }
        cout << setw(15) << fixed << setprecision(6) << a << setw(15) << b << setw(15) << f(a) << setw(15) << f(b) << setw(15) << c << setw(15) << f(c) << endl;
    }
    return c;
}
int main()
{
    double a, b;
    cout << "Enter the two range of the root [a,b] : " << endl;
    cin >> a >> b;
    double result = bisection_method(a, b);
    cout << "The approximate root is : " << result << endl;
}