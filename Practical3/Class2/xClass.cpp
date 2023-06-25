#include "xClass.h"
#include <iostream>
using namespace std;

// (1) constructor
xClass::xClass(int length, int max_val)
	: size(length)
{
	data = NULL;
	if (size <= 0) {
		cout << "illegal array size " << size << endl;
		return;
	}
	if (max_val <= 0) {
		cout << "illegal max_val " << max_val << endl;
		return;
	}

	if ((data = new int[size]) != NULL) {
		for (int i = 0; i < size; i++)
			data[i] = rand() % max_val;
	}
}

// (2) destructor
xClass::~xClass()
{
	delete[] data;
}

// (3) the print_data function
void xClass::print_data() const
{
	int* pi = data;
	int n = size;
	while (n-- > 0)
		cout << *pi++ << " ";
	cout << endl;
}

// (4) the ave_data function
int xClass::ave_data() const
{
	int av = 0;
	for (int i = 0; i < size; i++) av += data[i];
	av /= size;
	return av;
}

// (5) the data_at function
int xClass::data_at(int i) const
{
	if (i < 0 || i >= size) {
		cout << "out of bounds error i = " << i << endl;
		exit(0);
	}
	return *(data + i);
}

// (6) the range_data function
int xClass::range_data(int min, int max) const
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (data[i] >= min && data[i] <= max) count++;
	return count;
}

// (7) copy constructor
xClass::xClass(const xClass& b)
{
	size = b.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = b.data[i];
}

// (8) operator+=
void xClass::operator+=(const xClass& b)
{
	int new_size = size + b.size;
	int* new_data = new int[new_size];

	for (int i = 0; i < size; i++)
		new_data[i] = data[i];
	for (int i = 0; i < b.size; i++)
		new_data[i + size] = b.data[i];

	delete[] data;
	data = new_data;
	size = new_size;
}

