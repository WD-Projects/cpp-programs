#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
// Function to calculate f(x)
double f(double x) {
   return 3 * x - cos(x) - 1; // Example: f(x) = 3x - cosx - 1
}
// Function to calculate f'(x)
double fPrime(double x) {
    // Derivative of the example function: 3x - cosx - 1
    return 3 + sin(x);
}
// Function to perform Newton-Raphson method
double newtonRaphson(double x0, double tolerance, int maxIterations) {
    double x = x0;
    double h = tolerance + 1; // Initialize h to ensure first iteration runs
    int iteration = 0; 
    cout << setw(10) << "Iteration" << setw(15) << "x" << setw(15) << "f(x)" 
         << setw(15) << "f'(x)" << setw(15) << endl;
    while (abs(h) > tolerance && iteration < maxIterations) {
        double fx = f(x);
        double fpx = fPrime(x);
        // Check if derivative is too close to zero
        if (abs(fpx) < 1e-10) {
            cout << "Error: Derivative too close to zero. Method fails." << endl;
            return x;
        }
        // Calculate next approximation
        h = fx / fpx;
        double xNew = x - h; 
        // Print current iteration details
        cout << setw(10) << iteration  << fixed << setprecision(6) << setw(15) << x << setw(15) << fx  << setw(15) << fpx  << endl;
        // Update x for next iteration
        x = xNew;
        iteration++;
    }
    if (iteration >= maxIterations) {
        cout << "Maximum iterations reached." << endl;
    }
    return x;
}
int main() {
    double x0, tolerance;
    int maxIterations;
    cout << "Newton-Raphson Method for finding roots" << endl;
    // Input initial guess
    cout << "Enter initial guess (x0): ";
    cin >> x0;
    // Input tolerance
    cout << "Enter tolerance : ";
    cin >> tolerance;
    // Input maximum iterations
    cout << "Enter maximum number of iterations: ";
    cin >> maxIterations;
    cout << "Starting Newton-Raphson method..." << endl;
    // Find root using Newton-Raphson method
    double root = newtonRaphson(x0, tolerance, maxIterations);
    cout << "Final Results:" << endl;
    cout << "Root found: " << fixed << setprecision(6) << root << endl;
    cout << "f(root) = " << fixed << setprecision(6) << abs(f(root)) << endl;
    return 0;
}