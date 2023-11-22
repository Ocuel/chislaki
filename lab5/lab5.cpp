//5 lab 9 variant
#include <iostream>
#include <cmath>

using namespace std;

double function(double x)
{
	return (1 + x + x * x) / pow((x * x * x - 1), 1 / 2);
}

double function2(double x, double y)
{
	return x * x + 2 * y;
}

void firstmethod(double a, double b, double h, double xi, double x0, double xn, double result) {
	//formula trapeci
	for (double i = a + h; i < b; i = i + h)
	{
		xi = xi + function(i);
	}
	result = (0.5 * h) * (x0 + 2 * xi + xn);
	cout << result << endl;
}

void secondmethod(double a, double b, double m, double h, double xi, double x0, double xn, double result) {
	//formula simpsona
	h = (b - a) / m;
	double xnech = 0;
	for (double i = a + h; i < b; i = i + 2 * h)
	{
		xnech = xnech + function(i);
	}
	double xch = 0;
	for (double i = a + 2 * h; i < b; i = i + 2 * h)
	{
		xch = xch + function(i);
	}
	result = (h / 3) * (x0 + xn + 4 * xnech + 2 * xch);
	cout << result << endl;
}

void thirdmethod(double a, double b, double c, double d, double (*f)(double X, double Y))
{
	//kubaturnaya formula Simpsona
	double ih = 0;
	int m = 7000;
	int n = 0;
	ih = 0;
	n = m * 2;
	double x = a;
	double y = c;
	double hx = (b - a) / n;
	double hy = (d - c) / n;
	for (int i = 0; i < m - 1; ++i)
	{
		for (int j = 0; j < m - 1; ++j)
		{
			ih += (hx * hy / 9) * (f(x, y) + 4 * f(x + hx, y) + f(x + 2 * hx, y) + 4 * f(x, y + hy) + 16 * f(x + hx, y + hy) + 4 * f(x + 2 * hx, y + hy) + f(x, y + 2 * hy) + 4 * f(x + hx, y + 2 * hy) + f(x + 2 * hx, y + 2 * hy));
			y += 2 * hy;

		}
		x += 2 * hx;
		y = c;
	}
	cout << ih << endl;
}

int main()
{
	int n = 0;
	int m = 1;
	cout << "n?\n";
	cin >> n;
	while (m % 2 != 0)
	{
		cout << "m?\n";
		cin >> m;
	}
	double a = 1.0;
	double b = 2.631;
	double a2 = 0;
	double b2 = 2;
	double c = 0;
	double d = 1;
	double h = 0;
	double xi = 0;
	double x0 = function(a);
	double xn = function(b);
	double result = 0;
	h = (b - a) / n;
	firstmethod(a, b, h, xi, x0, xn, result);
	secondmethod(a, b, m, h, xi, x0, xn, result);
	thirdmethod(a2, b2, c, d, function2);
}
