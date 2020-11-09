#include <iostream>
#include <cmath>
using namespace std;
double h(const double x);
int main()
{
	double qp, qk, z;
	int n;
	cout << "qp = "; cin >> qp;
	cout << "qk = "; cin >> qk;
	cout << "n = "; cin >> n;
	double dg = (qk - qp) / n;
	double q = qp;
	while (q <= qk)
	{
		z = (h(q + 1) + h((q*q)+1)+((h(q*q)*(h(q*q)))));
		cout << q << " " << z << endl;
		q += dg;
	}
	return 0;
}
double h(const double x)
{
	if (abs(x) >= 1)
		return ((cos(x)+1)/((cos(x)*cos(x))+1));
	else
	{
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;
		do
		{
			i++;
			double R = -x * x / ((3 * i - 1) * 3 * i);
			a *= R;
			S += a;
		} while (i < 6);
		S = (S * (1 / cos(x)));
		return S;
	}
}