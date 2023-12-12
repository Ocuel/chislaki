//1 lab 9 var
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

const int n = 3;
int main()
{
    double A[n][n]{ {2.5, -3, 4.6},{-3.5, 2.6, 1.5},{-6.5, -3.5, 7.3} };
    double b[n]{-1.05, 14.46, -17.73};

    cout << "Massive A:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j];
            cout << "\t";
        }
        cout << endl;
    }
    cout << "Massive b:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << "\t";
    }
    cout << endl << endl;
    //Реализовываю прямой ход:
    double U[n][n]{ {6, 13, -17},{ 13,29,-38 },{-17,-38,50} };
    double q[n]{ 2,4,-5 };
    double Adiv = 0;

    for (int i = 0; i < n; i++)
    {
        q[i] = b[i] / A[i][i];

        if (i < n - 1)
        {
            Adiv = A[i + 1][i];

            b[i + 1] = b[i + 1] - q[i] * Adiv;
        }
        for (int j = 0; j < n; j++)
        {
            U[i][j] = A[i][j] / A[i][i];

            if (i < n - 1)
            {
                A[i + 1][j] = A[i + 1][j] - U[i][j] * Adiv;
            }
        }
    }
    // Для последней строчки:
    for (int i = 0; i < n - 1; i++)
    {
        U[n - 1][i] = 0;
    }
    cout << "Massive U:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << U[i][j];
            cout << "\t";
        }
        cout << endl;
    }
    cout << "Massive q:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << q[i] << "\t";
    }
    //Обратный ход:
    double x[n]{ 0,0,0 };

    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = q[i];
        for (int k = i + 1; k < n; k++)
        {
            x[i] = x[i] - U[i][k] * x[k];
        }
    }
    cout << endl << endl << "Massive x:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << "\t";
    }
    // 2. Вектор невязки
    double F[n]{ 0,0,0 };

    for (int i = 0; i < n; i++)
    {
        F[i] = U[i][0] * x[0] + U[i][1] * x[1] + U[i][2] * x[2] - q[i];
    }
    cout << endl << endl << "Massive F:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << F[i] << "\t";
    }
    return 0;
}