//2 lab 9 var﻿
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
    const double X1 = 1;
    const double X2 = 1;

    double x1 = X1;
    double x2 = X2;

    int iter = 0; //Количество итераций
    cout << "how many iterations?:" << endl;
    cin >> iter;

    const int n = 2;
    double F[n] = {};
    double J[n * n] = {};

    double deltax1 = 0;
    double deltax2 = 0;



    for (int i = 0; i < iter; i++)
    {
        //вектор невязки:
        F[0] = 1.5*x1*x1*x1-x2*x2-1;
        F[1] = x1*x2*x2*x2-x2-4;
        //матрица якоби:
        J[0] = -1 + 0.2 * (1 / (1 + x1 / 5 + x2 / 5));
        J[1] = 0.2 * (1 / (1 + x1 / 5 + x2 / 5)) - (1 / 3) * (cos(x2 / 3));
        J[2] = -(1 / 6) * x2 * sin(x1 * x2 / 6);
        J[3] = -(1 / 6) * x1 * sin(x1 * x2 / 6) - 1;
        //Решаем уравнения:
        deltax1 = (-1) * F[0] / (J[0] + J[1]);
        deltax2 = (-1) * F[1] / (J[2] + J[3]);
        //Новые значения:
        x1 = x1 + deltax1;
        x2 = x2 + deltax2;
        cout << setprecision(10) << x1 << "\t" << x2 << endl;
    }

    return 0;
}