#include <iostream>
#include <vector>
using namespace std;
double lagrangedoubleerpolation(vector<double> &x, vector<double> &y, double value, double n){
    double result = 0;
    for(int i = 0; i < n; i++){
        double term = 1;
        for(int j = 0; j < n; j++){
            if(i != j){
                term *= (value - x[j])/(x[i]-x[j]);
            }
        }
        result += (term * y[i]);
    }
    return result;
}
int main(){
    double n;
    cout <<  "Enter the value of array size = ";
    cin >> n;

    vector<double> x(n), y(n);
    double value, finalResult;

    cout << "Enter the values for array x:" << endl;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }

    cout << "Enter the values for array y:" << endl;
    for(int j = 0; j < n; j++){
        cin >> y[j];
    }

    cout << "Enter the value of f(x) = ";
    cin >> value;

    finalResult = lagrangedoubleerpolation(x, y, value, n);
    cout << finalResult;
}