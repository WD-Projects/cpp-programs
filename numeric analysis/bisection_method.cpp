#include <iostream>
#include <cmath>
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
    cout << "a\t\tb\t\tc\t\tf(c)" << endl;
    while (abs(b - a) >= 0.001)
    {
        c = (a + b) / 2;
        if(f(c) == 0){
            break;
        }
        if (f(a) * f(c) <= 0){
            b = c;
        }
        else{
            a = c;
        }
        cout << a << "\t\t" << b << "\t\t" << c << "\t\t" << f(c) << endl;
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