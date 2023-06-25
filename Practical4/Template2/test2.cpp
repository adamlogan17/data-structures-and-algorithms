#include <iostream>
#include <string>
#include "ssarray.h"

using namespace std;

int main()
{
	// array size
	int size = 5;

	// a double array
	sarray<double> dba(size);
	// in-bounds accesses
	for (int i = 0; i < size; i++)
		dba[i] = sqrt(i);
	for (int i = 0; i < size; i++)
		cout << dba[i] << " ";
	cout << endl;

	// a char array
	sarray<char> cha(size);
	// in-bounds accesses
	for (int i = 0; i < size; i++)
		cha[i] = 97 + i % 26;
	for (int i = 0; i < size; i++)
		cout << cha[i] << " ";
	cout << endl;

	// a string array
	sarray<string> stra(size);
	// in-bounds accesses
	for (int i = 0; i < size; i++)
		stra[i] = to_string(rand() % 65536);
	for (int i = 0; i < size; i++)
		cout << stra[i] << " ";
	cout << endl;

	// out of bounds accesses
	dba[size] = sqrt(size);
	cout << cha[size + 3] << endl;
	stra[-1] = "abcde";

	return 0;
}

/*class sarray {
public:
	sarray(int size);
	~sarray();

	int& operator[](int i);

private:
	int size;
	int* data;
};

sarray::sarray(int size)
	: size(size)
{
	if (size > 0) data = new int[size];
	else {
		cout << "illegal array size = " << size << endl;
		exit(0);
	}
}

sarray::~sarray()
{
	delete[] data;
}

int& sarray::operator[](int i)
{
	if (i < 0 || i >= size) {
		cout << "index " << i << " is out of bounds.";
		exit(0);
	}
	return data[i];
}

int main()
{
	// create a 10-element array
	sarray array(10);

	// in-bound access, [] is used on the left side or an assignment
	array[5] = 23;
	// in-bound access, [] is used on the right side of an operation
	cout << array[5] << endl;

	// out-of-bound accesses
	array[13] = 392;
	cout << array[-1] << endl;

	return 0;
}*/
