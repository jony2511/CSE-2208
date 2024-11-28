#include <bits/stdc++.h>
using namespace std;

// Function representing dy/dx = cos(x)
double dydx(double x, double y)
{
    return cos(x);
}

// Exact solution for dy/dx = cos(x) with y(0) = 0
double exact_solution(double x)
{
    return sin(x);
}

int main()
{
    double x0 = 0.0, y0 = 0.0; // Initial condition: y(0) = 0
    double h = 0.1;            // Step size
    int steps = 10;

    cout << "Enter step size (h) and number of steps: ";
    cin >> h >> steps;

    cout << setw(10) << "Iteration" << setw(10) << "x" << setw(15) << "RK(y)" << setw(15) << "Exact(y)" << setw(15) << "Error" << endl;
    cout << fixed << setprecision(5);

    for (int i = 0; i <= steps; i++)
    {
        // Runge-Kutta calculations
        double k1 = h * dydx(x0, y0);
        double k2 = h * dydx(x0 + h / 2, y0 + k1 / 2);
        double k3 = h * dydx(x0 + h / 2, y0 + k2 / 2);
        double k4 = h * dydx(x0 + h, y0 + k3);

        double y_rk = y0 + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;  // RK-4 update
        double y_exact = exact_solution(x0);                  // Exact solution
        double error = abs(y_rk - y_exact);                   // Absolute error

        // Output results
        cout << setw(10) << i << setw(10) << x0 << setw(15) << y_rk << setw(15) << y_exact << setw(15) << error << endl;

        // Update for the next step
        y0 = y_rk;
        x0 += h;
    }

    return 0;
}
