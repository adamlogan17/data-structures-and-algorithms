#include <iostream>

using namespace std;

int main()
{
	int i = 27;			// declare an int variable
	int* pi = &i;		// declare an int pointer pi pointing to the address of i
	cout << "value of i is " << i << endl;
	cout << "value of pi (i.e. address of i) is " << pi << endl;
	cout << "value pi is pointing to, or from dereferencing pi, is " << *pi << endl;

	*pi = 35;			// change the value of i via dereferencing pi
	cout << "value of i is " << i << endl;
	*pi = *pi * 2;		// double the value of i via dereferencing pi
	cout << "value of i is " << i << endl;

	double* pd = NULL;	// declare a double pointer 
						// always initialise an unused pointer to NULL
	cout << "value of pd is " << pd << endl;
	// cout << "value pd is pointing to is" << *pd;
						// program crashes because you try to dereference NULL 
						// NULL is not a valid memory address
						// comment the above line to continue the test below

	// uncomment the following code
	// the code tries to print the value of x, which is 10, via pointer px but is wrong. Correct it.
	/*
	int* px = NULL;
	int x = 10;
	*px = x;
	cout << &px << endl;
	*/

	// the correct code
	int* px = NULL;
	int x = 10;
	px = &x;
	cout << *px << endl;

	return 0;
}