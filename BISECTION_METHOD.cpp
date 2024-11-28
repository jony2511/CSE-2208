#include <bits/stdc++.h>
using namespace std;

vector<double> coeffs, ans;

// Function to evaluate the polynomial at a given x using Horner's Rule
double fx(double x)
{
    double res = 0.0;
    for (int i = 0; i < coeffs.size(); ++i)
    {
        res = res * x + coeffs[i];
    }
    return res;
}

// Bisection method implementation
double bisection(double a, double b)
{
    if (fx(a) * fx(b) >= 0)
    {
        throw invalid_argument("No sign change in interval. Bisection method cannot be applied");
    }

    int maxIterations = 1000;
    double tolerance = 0.00001;
    double c = a;

    for (int i = 0; i < maxIterations; i++)
    {
        c = (a + b) / 2; // Midpoint
        double fc = fx(c);

        if (fabs(fc) < tolerance || fabs(b - a) / 2 < tolerance)
            return c;

        // Narrow down the interval
        if (fc * fx(a) < 0)
            b = c;
        else
            a = c;
    }

    return c;
}

int main()
{
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    vector<double> coefficients(degree + 1);
    cout << "Enter the coefficients of the polynomial from highest to lowest degree:\n";
    for (int i = 0; i <= degree; i++)
    {
        cin >> coefficients[i];
    }

    coeffs = coefficients; // Assign input coefficients to global variable

    for (int i = 0; i < degree; i++) // Expect up to `degree` roots
    {
        double a, b;
        cout << "Enter the interval [a, b] for root " << i + 1 << ": ";
        cin >> a >> b;

        try
        {
            double root = bisection(a, b);
            ans.push_back(root);
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << " for interval [" << a << ", " << b << "]\n";
        }
    }

    cout << "\nRoots found:\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Root " << i + 1 << ": " << ans[i] << endl;
    }

    return 0;
}
