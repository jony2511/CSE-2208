#include<bits/stdc++.h>
using namespace std;
vector<double> coeffs;

double fx(double x)
{
    double res = 0.0;
    int n=coeffs.size();
    for (int i = 0; i < n; ++i)
        res+=coeffs[i]*pow(x,n-i-1);
    return res;
}

double fdx(double x)
{
    double res = 0.0;
    int n=coeffs.size();
    for (int i = 0; i < n - 1; ++i)
        res+= coeffs[i]*(n-i-1)*pow(x,n-i-2);
    return res;
}

double newtonRaphson(double x0)
{
    double tol = 1e-6;
    int maxIt = 1000;
    double x = x0;
    for (int i = 0; i < maxIt; i++)
    {
        double f = fx(x);
        double fPrime = fdx(x);
        if (fabs(fPrime) < 1e-10)
        {
            cout << "Method failed for too small derivative." << endl;
            return x;
        }
        double x1=x- f /fPrime;
        if (fabs(x1 - x) < tol)
            return x1;
        x = x1;
    }

    cout << "Method not converge within the maximum iterations." << endl;
    return x;
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
    {
        int a;
        cin>>a;
        coeffs.push_back(a);
    }

    double x0;
    cout << "Enter initial guess: ";
    cin >> x0;
    vector<double> ans;
    for (int i = 0; i < n; ++i)
    {
        double root = newtonRaphson(x0);
        ans.push_back(root);
        coeffs = def( root);
    }

    cout << endl<<"Roots found:" << endl;
    for (int i=0; i<ans.size(); i++)
    {
        cout <<"x"<<i+1<<" = "<<ans[i]<<endl;
    }

    return 0;
}
