#include <bits/stdc++.h>
using namespace std;

void gauss_seidel(vector<double>vec[], int n)
{
    vector<double> x(n, 0.0);
    int maxIt=10000;
    double tol=0.0001;
    cout<<endl<<"**********GAUSS-SEIDEL METHOD********"<<endl;
    for (int it = 0; it < maxIt; it++)
    {
        double err = 0.0;
        for (int i = 0; i < n; i++)
        {
            double sum = vec[i][n];
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    sum -= vec[i][j] * x[j];
            }
            double x1 = sum / vec[i][i];
            err += fabs(x1 - x[i]);
            x[i] = x1;
        }
        err /= n;
        if (err < tol)
        {
            cout<<endl<<"The result: "<<endl;
            for (int i = 0; i < n; i++)
                cout << "x" << i + 1 << " = " << x[i] << "\n";
            cout<<endl;
            return;
        }
    }
    cout << "Did not converge within the maximum iterations.\n";
}

int main()
{
    int n;
    cout<<"Enter number of equations: ";
    cin>>n;

    vector<double>ara[n];
    cout <<"Enter equations:\n";
    for(int i = 0; i < n; i++)
    {
        cout<<"Equation " << i + 1 << ": ";
        for (int j = 0; j <= n; j++)
        {
            double temp;
            cin >> temp;
            ara[i].push_back(temp);
        }
    }

    gauss_seidel(ara,n);

    return 0;
}
