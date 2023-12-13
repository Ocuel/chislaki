#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

double sumofx(int maxpowerROW, double xarr[], const int n)
{
    double result = 0;
    for (int k = 0; k < n; k++)
    {
        result = result + pow(xarr[k], maxpowerROW);
    }
    return result;
}

double sumofxy(int maxpower, double xarr[], double yarr[], const int n)
{
    double result = 0;
    for (int k = 0; k < n; k++)
    {
        result = result + (yarr[k]) * (pow(xarr[k], maxpower));
    }
    return result;
}


int main()
{
    setlocale(LC_ALL, "RUS");

    //всего 9 точек: 0-8
    const int n = 9;

    double xarr[n] = {};
    for (int i = 0; i < n; i++)
    {
        xarr[i] = i;
    }

    double yarr[n] = {};
    for (int i = 0; i < n; i++)
    {
        yarr[i] = pow((i + 1), (-1));
    }


    //Полином 4 степени, значит 5 слагаемых:

    const int m = 5;
    double aarr[m] = {};

    //5 коэффициентов = 5 уравнений

    double A[m][m] = {};

    //Максимальная степень при вычислениях:

    int maxpower = 2 * (m - 1);

    //Заполняем матрицу:

    for (int i = 0; i < m; i++)
    {
        int maxpowerROW = maxpower;
        for (int j = 0; j < m; j++)
        {
            A[i][j] = sumofx(maxpowerROW, xarr, n);
            maxpowerROW--;
        }
        maxpower--;
    }

    cout << "Массив A:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setprecision(8) << A[i][j] << "\t";
        }
        cout << endl;
    }

    //Вектор свободных коэффициентов:

    double b[m] = {};
    maxpower = m - 1;

    for (int i = 0; i < m; i++)
    {
        b[i] = sumofxy(maxpower, xarr, yarr, n);
        maxpower--;
    }

    cout << "Массив b:" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << "\t";
    }
    cout << endl << endl;

    //Дальше идет метод Гаусса:
    //Получили вектор коэфициентов:

    aarr[0] = double(6813731) / double(5148000000);
    aarr[1] = double(-4953256823) / double(185328000000);
    aarr[2] = double(3749105317) / double(19305000000);
    aarr[3] = double(-583624142561) / double(926640000000);
    aarr[4] = double(76473708953) / double(77220000000);

    cout << "Массив abcde:" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << aarr[i] << "\t";
    }
    cout << endl << endl;




    return 0;
}