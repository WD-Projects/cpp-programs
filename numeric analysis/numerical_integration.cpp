#include <iostream>
#include <cmath>
using namespace std;
double f(double x){
    return (2000 * log(140000 / (140000 - 2100 * x)) - 9.8 * x);
}
double simpson_oneThird_rule(double a, double b, int n){
    if(n % 2 != 0){
        return -1;
    }
    double h = (b - a) / n;
    double result = 0;
    for(int i = 0; i <= n; i++){
        double x = (a + (i * h));
        int coefficient = (i % 2 == 0) ? 2 : 4;
        result = result + (coefficient * f(x));
    }
    return ((h/3) * (result - (f(a) + f(b))));
}
double simpson_threeByEight_rule(double a, double b, int n){
    if(n % 3 != 0){
        return -1;
    }
    double h = (b - a) / n;
    double result = 0;
    for(int i = 0; i <= n; i++){
        double x = (a + (i * h));
        int coefficient = (i % 3 == 0) ? 2 : 3;
        result = result + (coefficient * f(x));
    }
    return (((3 * h) / 8) * (result - (f(a) + f(b))));
}
double trapezoidal_rule(double a, double b, int n){
    double h = (b - a) / n;
    double result = 0;
    for(int i = 0; i <= n; i++){
        double x = (a + (i * h));
        result = result + (2 * f(x));
    }
    return ((h/2) * (result - (f(a) + f(b))));
}
int main(){
    double a, b, n;
    cout << "Enter the lower limit = ";
    cin >> a;
    cout << "Enter the upper limit = ";
    cin >> b;
    cout << "Enter the number of segment = ";
    cin >> n;
    double finalResult_1 = simpson_oneThird_rule(a, b, n);
    double finalResult_2 = simpson_threeByEight_rule(a, b, n);
    double finalResult_3 = trapezoidal_rule(a, b, n);
    if(finalResult_1 != -1){
        cout << "simpson_oneThird solution is : " << finalResult_1 << endl;
    }
    if(finalResult_2 != -1){
        cout << "simpson_threeByEight solution is : " << finalResult_2 << endl;
    }
    if(finalResult_3 != -1){
        cout << "trapezoidal solution is : " << finalResult_3 << endl;
    }
} 