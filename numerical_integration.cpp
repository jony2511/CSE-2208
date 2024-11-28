#include <bits/stdc++.h>
using namespace std;

// Example function f(x)
double f(double x) {
    return x * x * sin(x); // Replace this with your desired function
}

// Trapezoidal Rule
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n; // Step size
    double integral = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; ++i) {
        integral += f(a + i * h);
    }

    return integral * h;
}

// Simpson's 1/3 Rule
double simpsonsOneThirdRule(double a, double b, int n) {
    if (n % 2 != 0) {
        cout << "Simpson's 1/3 Rule requires an even number of intervals.\n";
        return NAN;
    }

    double h = (b - a) / n; // Step size
    double integral = f(a) + f(b);

    for (int i = 1; i < n; ++i) {
        if (i % 2 == 0) {
            integral += 2 * f(a + i * h);
        } else {
            integral += 4 * f(a + i * h);
        }
    }

    return integral * h / 3.0;
}

// Simpson's 3/8 Rule
double simpsonsThreeEighthRule(double a, double b, int n) {
    if (n % 3 != 0) {
        cout << "Simpson's 3/8 Rule requires the number of intervals to be a multiple of 3.\n";
        return NAN;
    }

    double h = (b - a) / n; // Step size
    double integral = f(a) + f(b);

    for (int i = 1; i < n; ++i) {
        if (i % 3 == 0) {
            integral += 2 * f(a + i * h);
        } else {
            integral += 3 * f(a + i * h);
        }
    }

    return integral * 3.0 * h / 8.0;
}

int main() {
    double a, b;
    int n;

    // Input the interval and number of subintervals
    cout << "Enter the lower limit of integration (a): ";
    cin >> a;
    cout << "Enter the upper limit of integration (b): ";
    cin >> b;
    cout << "Enter the number of subintervals (n): ";
    cin >> n;

    // Trapezoidal Rule
    double trapezoidal = trapezoidalRule(a, b, n);
    cout << fixed << setprecision(8);
    cout << "Trapezoidal Rule Approximation: " << trapezoidal << endl;

    // Simpson's 1/3 Rule
    double simpsonsOneThird = simpsonsOneThirdRule(a, b, n);
    if (!isnan(simpsonsOneThird)) {
        cout << "Simpson's 1/3 Rule Approximation: " << simpsonsOneThird << endl;
    }

    // Simpson's 3/8 Rule
    double simpsonsThreeEighth = simpsonsThreeEighthRule(a, b, n);
    if (!isnan(simpsonsThreeEighth)) {
        cout << "Simpson's 3/8 Rule Approximation: " << simpsonsThreeEighth << endl;
    }

    return 0;
}
