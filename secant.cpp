#include <bits/stdc++.h>
using namespace std;
vector<double> coeffs,ans;

double fx(double x)
{
    double res = 0.0;
    int n=coeffs.size();
    for (int i = 0; i < n; ++i)
        res+=coeffs[i]*pow(x,n-i-1);
    return res;
}

double secantMethod(double x0, double x1)
{
    int maxIter=1000;
    double tol=0.00001;
    double x2;
    for (int i = 0; i < maxIter; ++i)
    {
        double f_x0 = fx(x0);
        double f_x1 = fx(x1);

        if (fabs(f_x1 - f_x0) < 1e-10)
        {
            cout << "Division by zero error in method." << endl;
            return x1;
        }
        x2 = x1 - f_x1 * (x1 - x0) / (f_x1 - f_x0);

        if (fabs(x2 - x1) < tol)
        {
            return x2;
        }

        x0 = x1;
        x1 = x2;
    }

    cout << "Method did not converge within the maximum iterations." << endl;
    return x2;
}

vector<double> def(double root)
{
    int n = coeffs.size();
    vector<double> deft(n - 1);
    deft[0] = coeffs[0];
    for (int i = 1; i < n - 1; ++i)
    {
        deft[i] = coeffs[i];
        deft[i]+= deft[i - 1] * root;
    }
    return deft;
}


int main()
{
           int n;
        cout << "Enter degree of equation: ";
        cin >> n;
        coeffs.resize(n + 1);
        cout << "Enter the coefficients: ";
        for (int i=0; i<=n; i++)
            cin>>coeffs[i];


    for (int k = 0; k<n; k++)
    {
        double x0, x1;
        cout << "Enter two initial guesses to find root "<<k+1<<": ";
        cin >> x0 >> x1;

        double root = secantMethod(x0, x1);
        ans.push_back(root);

        coeffs = def( root);
    }

    cout << "\nRoots found:\n";
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << "Root " << i + 1 << ": " << fixed << setprecision(6) << ans[i] << endl;
    }

    return 0;
}
