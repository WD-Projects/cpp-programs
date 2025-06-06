#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

// Function to perform Gauss Elimination
void gaussElimination(vector<vector<double>>& augmentedMatrix, int n) {
    // Forward Elimination
    for(int i = 0; i < n; i++) {
        // Find pivot
        int maxRow = i;
        for(int k = i + 1; k < n; k++) {
            if(abs(augmentedMatrix[k][i]) > abs(augmentedMatrix[maxRow][i])) {
                maxRow = k;
            }
        }
        // Swap rows if necessary
        if(maxRow != i) {
            swap(augmentedMatrix[i], augmentedMatrix[maxRow]);
        }    
        // Make all rows below this one 0 in current column
        for(int k = i + 1; k < n; k++) {
            double factor = augmentedMatrix[k][i] / augmentedMatrix[i][i];
            for(int j = i; j <= n; j++) {
                augmentedMatrix[k][j] -= factor * augmentedMatrix[i][j];
            }
        }
    }
}
// Function to perform back substitution
vector<double> backSubstitution(vector<vector<double>>& augmentedMatrix, int n) {
    vector<double> solution(n);
    for(int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for(int j = i + 1; j < n; j++) {
            sum += augmentedMatrix[i][j] * solution[j];
        }
        solution[i] = (augmentedMatrix[i][n] - sum) / augmentedMatrix[i][i];
    }
    return solution;
}

// Function to print the augmented matrix
void printMatrix(const vector<vector<double>>& matrix, int n) {
    cout << "Augmented Matrix: " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            cout << fixed << setprecision(4) << setw(10) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;
    // Create augmented matrix
    vector<vector<double>> augmentedMatrix(n, vector<double>(n + 1));
    // Input coefficients
    cout << "Enter the coefficients of the equations: " << endl;
    for(int i = 0; i < n; i++) {
        cout << "Equation " << i + 1 << ":\n";
        for(int j = 0; j < n; j++) {
            cout << "Coefficient of x" << j + 1 << ": ";
            cin >> augmentedMatrix[i][j];
        }
        cout << "Right-hand side value: ";
        cin >> augmentedMatrix[i][n];
    }
    // Print original matrix
    cout << "Original System:" << endl;
    printMatrix(augmentedMatrix, n);
    // Perform Gauss Elimination
    gaussElimination(augmentedMatrix, n);
    // Print matrix after elimination
    cout << "\nMatrix after Gauss Elimination:";
    printMatrix(augmentedMatrix, n);
    // Perform back substitution
    vector<double> solution = backSubstitution(augmentedMatrix, n);
    // Print solution
    cout << "Solution:" << endl;
    for(int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << solution[i] << endl;
    }
}
