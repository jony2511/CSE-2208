#include <bits/stdc++.h>
using namespace std;

void jacobiMethod(vector<double> vec[], int n)
{
    vector<double> x(n,0.0),x1(n, 0.0);
    int maxIt=1000;
    double tol=0.0001;
    cout<<endl<<"**********JACOBI ITERATIVE METHOD********"<<endl;
    for (int it = 0; it < maxIt; it++)
    {
        for (int i = 0; i < n; i++)
        {
            double sum = vec[i][n];
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    sum -= vec[i][j] * x[j];
            }
            x1[i] = sum / vec[i][i];
        }

        double err = 0.0;
        for (int i = 0; i < n; i++)
            err += fabs(x1[i] - x[i]);

        err /= n;

        if (err< tol)
        {
            cout<<endl<<"The result: "<<endl;
            for (int i = 0; i < n; i++)
                cout << "x" << i + 1 << " = " << x1[i] << "\n";
            cout<<endl;
            return;
        }
        x = x1;
    }
    cout << "Did not converge within the maximum iterations.\n";
}

int main()
{
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<double>vec[n];
    cout << "Enter equations:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Equation " << i + 1 << ": ";
        for (int j = 0; j <= n; j++)
        {
            double temp;
            cin >> temp;
            vec[i].push_back(temp);
        }
    }

    // Calling Jacobi method
    jacobiMethod(vec, n);

    return 0;
}
