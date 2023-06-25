#include "myLib.h"
#include <iostream>
using namespace std;

void mul_div(double* first, double* second)
{
	double temp = (*first) * (*second);
	*second = (*first) / (*second);
	*first = temp;
}

int search(char* pchs, int size, char key)
{
	int count = 0;

	// using array indexing to cycle through the array
	for (int n = 0; n < size; n++) {
		if (pchs[n] == key)
			count++;
	}

	// using pointer arithmetic to cycle through the array
	/*count = 0;
	char* pend = pchs + size;
	for (pchs; pchs < pend; pchs++)
		if (*pchs == key)
			count++;*/

	return count;
}

bool bResizeArray(int*& pi, int& size, int sizeNew)
{
	// allocate new array
	int* piNew = NULL;
	if (sizeNew <= 0 || (piNew = new int[sizeNew]) == NULL)
		return false;	// resize fails

	// if expanding, initialise the new tail to zero
	if (sizeNew > size) {
		for (int i = 0; i < size; i++)
			piNew[i] = pi[i];
		for (int i = size; i < sizeNew; i++)
			piNew[i] = 0;
	}

	// if shrinking, erase the tail contents
	else {
		for (int i = 0; i < sizeNew; i++)
			piNew[i] = pi[i];
	}

	// delete old array
	delete[] pi;

	// point pi to the new array, and update size to sizeNew
	pi = piNew;
	size = sizeNew;

	// resize successful
	return true;
}

bool bAddArrays(char*& pchs, int& size, char* pchs2, int size2)
{
	// allocate new array
	char* pchsNew = NULL;
	if ((pchsNew = new char[size + size2]) == NULL)
		return false;	// concatenation fails

	// copy 1st array content to pchNew
	for (int i = 0; i < size; i++)
		pchsNew[i] = pchs[i];
	delete[] pchs;		// delete 1st array

	// copy 2nd array content to pchNew
	for (int i = 0; i < size2; i++)
		pchsNew[size + i] = pchs2[i];

	// pchs points to the new array & size = size + size2
	pchs = pchsNew;
	size += size2;

	// concatenation successful
	return true;
}

bool bInsert(int*& pi, int& size, int pos, int val)
{
	if (pos < 0 || pos > size) {
		cout << "pos is out of range" << endl;
		return false;
	}

	// new array size after insertion
	size++;
	// new array
	int* piNew = new int[size];
	if (piNew == NULL)
		return false;

	// copt pi to piNew & insert val
	for (int i = 0; i < pos; i++) piNew[i] = pi[i];
	piNew[pos] = val;
	for (int i = pos + 1; i < size; i++) piNew[i] = pi[i - 1];

	// delete old array
	delete[] pi;
	// point pi to the new array
	pi = piNew;

	return true;
}
