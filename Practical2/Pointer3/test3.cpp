#include <iostream>

using namespace std;

void mul_div(double* first, double* second)
{
	double temp = (*first) * (*second);
	*second = (*first) / (*second);
	*first = temp;
}

int main()
{
	double a = 12.0, b = 4.0;
	mul_div(&a, &b);
	cout << a << " " << b << endl;

	return 0;
}