#include <iostream>
using namespace std;

// loop based implementation
//double rsquare(int n)
//{
//	double sum = 0.;
//	for (double i = 1; i <= n; i++)
//		sum += 1. / (i * i);
//	return sum;
//}

// recursion based implementation
double rsquare(int n)
{
	// base case
	if (n == 1)
		return 1.;
	// recursive case
	return
		rsquare(n - 1) + 1. / (double(n) * double(n));
}

int main()
{
	int n = 1000;
	cout << "Limit = " << (3.1415926 * 3.1415926) / 6. << "\nSum of " << n << " terms = " << rsquare(n) << endl;
	return 0;
}
