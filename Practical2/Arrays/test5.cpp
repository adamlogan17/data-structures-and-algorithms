#include <iostream>

using namespace std;

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

int main()
{
	// first array
	int size = 100;
	char* pchs = new char[size];
	for (int i = 0; i < size; i++)
		pchs[i] = 'a';
	strcpy_s(pchs, size, "This is 1st string. ");	// copy a string
	size = strlen(pchs) - 1;	// get the length of a string

	// 2nd array
	int size2 = 100;
	char* pchs2 = new char[size2];
	strcpy_s(pchs2, size2, " This is 2nd string.");	// copy a string
	size2 = strlen(pchs2) + 1;	// get the length of a string

	// add pchs2 to pchs, return new array in pchs
	if (bAddArrays(pchs, size, pchs2, size2)) {
		cout << pchs << endl;
	}

	// free arrays memory
	delete[] pchs2;
	delete[] pchs;

	return 0;
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

int main1()
{
	// old array
	int size = 10;
	int* pi = new int[size];
	for (int i = 0; i < size; i++)
		pi[i] = i;
	for (int i = 0; i < size; i++)
		cout << pi[i] << " ";
	cout << endl;

	// expanding
	if (bResizeArray(pi, size, 20)) {
		for (int i = 0; i < size; i++)
			cout << pi[i] << " ";
		cout << endl;
	}

	// shrinking
	if (bResizeArray(pi, size, 5)) {
		for (int i = 0; i < size; i++)
			cout << pi[i] << " ";
		cout << endl;
	}

	// free array memory
	delete[] pi;

	return 0;
}
