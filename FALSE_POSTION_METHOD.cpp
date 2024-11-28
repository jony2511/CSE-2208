#include <bits/stdc++.h>
using namespace std;

vector<double> coeffs;

double fx(double x)
{
    double res = 0.0;
    int n = coeffs.size();
    for (int i = 0; i < n; ++i)
        res += coeffs[i] * pow(x, n - i - 1);
    return res;
}

double false_position(double a, double b)
{
    double c = a;
    int maxIt = 1000;
    double tol = 0.00001;
    for (int i = 0; i < maxIt; i++)
    {
        double fa = fx(a);
        double fb = fx(b);
        c = (a * fb - b * fa) / (fb - fa);
        double fc = fx(c);
        if (fabs(fc) < tol || fabs(b - a) < tol)
            return c;
        if (fa * fc < 0)
            b = c;
        else
            a = c;
    }
    return c;
}

vector<double> def(double root)
{
    int n = coeffs.size();
    vector<double> deft(n - 1);
    deft[0] = coeffs[0];
    for (int i = 1; i < n - 1; ++i)
    {
        deft[i] = coeffs[i];
        deft[i] += deft[i - 1] * root;
    }
    return deft;
}

int main()
{
    int n;
    cout << "Enter the degree of the polynomial: ";
    cin >> n;
    coeffs.resize(n + 1);
    cout << "Enter the coefficients: ";
    for (int i = 0; i <= n; i++)
    {
        cin >> coeffs[i];
    }

    vector<double> ans;

    while(n--)
    {
        double an = coeffs[0];
        double an_1 = coeffs[1];
        double an_2 = coeffs[2];

        double xmax = sqrt(pow(an_1 / an, 2) - 2 * (an_2 / an));

        double a = -fabs(xmax), b = fabs(xmax);
        double root = false_position(a, b);
        ans.push_back(root);
        coeffs = def(root);
    }

    cout << endl << "Roots found:" << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "x" << i + 1 << " = " << ans[i] << endl;
    }

    return 0;
}
