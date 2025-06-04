#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function to calculate f(x)
double f(double x) {
    // Example function: x^3 - x - 1
    return x * x * x - x - 1;
}

// Function to calculate f'(x)
double fPrime(double x) {
    // Derivative of the example function: 3x^2 - 1
    return 3 * x * x - 1;
}

// Function to perform Newton-Raphson method
double newtonRaphson(double x0, double tolerance, int maxIterations) {
    double x = x0;
    double h;
    int iteration = 0;
    
    cout << "Iteration\tx\t\tf(x)\t\tf'(x)\t\tError" << endl;
    
    do {
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
        
        // Calculate relative error
        double error = abs((xNew - x) / xNew) * 100;
        
        // Print current iteration details
        cout << setw(9) << iteration << "\t"
             << fixed << setprecision(6) << setw(12) << x << "\t"
             << setw(12) << fx << "\t"
             << setw(12) << fpx << "\t"
             << setw(12) << error << "%" << endl;
        
        // Update x for next iteration
        x = xNew;
        iteration++;
        
        // Check if maximum iterations reached
        if (iteration >= maxIterations) {
            cout << endl << "Maximum iterations reached." << endl;
            break;
        }
        
    } while (abs(h) > tolerance);
    
    return x;
}

int main() {
    double x0, tolerance;
    int maxIterations;
    
    cout << "Newton-Raphson Method for finding roots" << endl;
    cout << "----------------------------------------" << endl;
    
    // Input initial guess
    cout << "Enter initial guess (x0): ";
    cin >> x0;
    
    // Input tolerance
    cout << "Enter tolerance (e.g., 0.0001): ";
    cin >> tolerance;
    
    // Input maximum iterations
    cout << "Enter maximum number of iterations: ";
    cin >> maxIterations;
    
    cout << endl << "Starting Newton-Raphson method..." << endl;
    
    // Find root using Newton-Raphson method
    double root = newtonRaphson(x0, tolerance, maxIterations);
    
    cout << endl << "Final Results:" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Root found: " << fixed << setprecision(6) << root << endl;
    cout << "f(root) = " << fixed << setprecision(6) << f(root) << endl;
    
    return 0;
}