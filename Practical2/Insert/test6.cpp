#include <iostream>

using namespace std;

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
	for (int i = 0; i < pos; i++)
		piNew[i] = pi[i];
	piNew[pos] = val;
	for (int i = pos + 1; i < size; i++)
		piNew[i] = pi[i - 1];

	// delete old array
	delete[] pi;
	// point pi to the new array
	pi = piNew;

	return true;
}

int main()
{
	// the array before insertion
	int size = 0;
	int* pi = NULL;

	// insert 10 40s at the end of the array
	for (int i = 0; i < 10; i++) {
		if (!bInsert(pi, size, i, 40)) {
			cout << "Insertion fails" << endl;
			return 1;
		}
	}
	// print the array
	for (int i = 0; i < size; i++)
		cout << pi[i] << " ";
	cout << endl;

	// insert a value 0 at position 3
	if (!bInsert(pi, size, 3, 0)) {
		cout << "Insertion fails" << endl;
		return 1;
	}
	// print the array
	for (int i = 0; i < size; i++)
		cout << pi[i] << " ";
	cout << endl;

	// delete array
	delete[] pi;

	return 0;
}
