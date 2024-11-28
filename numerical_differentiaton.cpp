#include <bits/stdc++.h>
using namespace std;

// Example function f(x)
double f(double x) {
    return x * x * sin(x);  // Replace this with your desired function
}

// Numerical differentiation using finite differences
double forwardDifference(double x, double h) {
    return (f(x + h) - f(x)) / h;
}

double backwardDifference(double x, double h) {
    return (f(x) - f(x - h)) / h;
}

double centralDifference(double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

int main() {
    double x, h;

    // Input the point and step size
    cout << "Enter the point x at which to differentiate: ";
    cin >> x;
    cout << "Enter the step size h: ";
    cin >> h;

    // Compute derivatives using finite differences
    double fwd = forwardDifference(x, h);
    double bwd = backwardDifference(x, h);
    double central = centralDifference(x, h);

    // Output results
    cout << fixed << setprecision(8);
    cout << "Forward Difference Approximation: " << fwd << endl;
    cout << "Backward Difference Approximation: " << bwd << endl;
    cout << "Central Difference Approximation: " << central << endl;

    // Exact derivative if known (optional for comparison)
    double exact_derivative = 2 * x * sin(x) + x * x * cos(x);  // Derivative of f(x) = x^2 * sin(x)
    cout << "Exact Derivative: " << exact_derivative << endl;

    return 0;
}

