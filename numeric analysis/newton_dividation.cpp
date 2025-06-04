#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// Function to calculate divided differences
void calculateDividedDifferences(vector<double>& x, vector<double>& y, vector<vector<double>>& dd) {
    int n = x.size();
    
    // Initialize the first column with y values
    for(int i = 0; i < n; i++) {
        dd[i][0] = y[i];
    }
    
    // Calculate divided differences
    for(int j = 1; j < n; j++) {
        for(int i = 0; i < n - j; i++) {
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1]) / (x[i+j] - x[i]);
        }
    }
}

// Function to evaluate the interpolating polynomial at a given point
double evaluatePolynomial(double x, vector<double>& x_points, vector<vector<double>>& dd) {
    int n = x_points.size();
    double result = dd[0][0];
    double term = 1.0;
    for(int i = 1; i < n; i++) {
        term *= (x - x_points[i-1]);
        result += dd[0][i] * term;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;
    vector<double> x(n), y(n);
    vector<vector<double>> dd(n, vector<double>(n, 0.0));
    // Input data points
    cout << "Enter the data points (x, y):" << endl;
    for(int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i];
    } 
    // Calculate divided differences
    calculateDividedDifferences(x, y, dd);
    // Display the divided difference table
    cout << "Divided Difference Table:" << endl;
    cout << "x\t\ty\t\t";
    for(int i = 1; i < n; i++) {
        cout << "DD" << i << "\t\t";
    }
    cout << "\n";
    for(int i = 0; i < n; i++) {
        cout << x[i] << "\t\t";
        for(int j = 0; j < n-i; j++) {
            cout << fixed << setprecision(4) << dd[i][j] << "\t\t";
        }
        cout << "\n";
    }
    // Evaluate polynomial at a point
    double x_eval;
    cout << "\nEnter the point to evaluate the polynomial: ";
    cin >> x_eval;
    double result = evaluatePolynomial(x_eval, x, dd);
    cout << "\nThe interpolated value at x = " << x_eval << " is: " << fixed << setprecision(6) << result << endl;
    return 0;
}
