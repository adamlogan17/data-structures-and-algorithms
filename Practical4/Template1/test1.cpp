#include <iostream>
#include "Person.h"

using namespace std;

template<typename T>
bool bInsert(T*& pi, int& size, int pos, T val)
{
	if (pos < 0 || pos > size) {
		cout << "pos is out of range" << endl;
		return false;
	}

	// new array size after insertion
	size++;
	// new array
	T* piNew = new T[size];
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
	// test 1 - insert an element in a string array
	int size = 5;
	string* pstrs = new string[size];
	pstrs[0] = "abc";
	pstrs[1] = "def";
	pstrs[2] = "jkl";
	pstrs[3] = "mno";
	pstrs[4] = "pqr";
	for (int i = 0; i < size; i++)
		cout << pstrs[i] << " ";
	cout << endl;

	if (bInsert(pstrs, size, 2, string("ghi")))
	{
		for (int i = 0; i < size; i++)
			cout << pstrs[i] << " ";
	}
	cout << endl << endl;

	// test 2 - insert an object in a Person array
	size = 10;
	Person* pps = new Person[size];
	for (int i = 0; i < size; i++)
		pps[i].print();
	cout << endl;

	if (bInsert(pps, size, 4, Person("Jack", "Smith", "123456", 1990)))
	{
		for (int i = 0; i < size; i++)
			pps[i].print();
	}

	return 0;
}
