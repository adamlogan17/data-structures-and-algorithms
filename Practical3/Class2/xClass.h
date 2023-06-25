#ifndef XCLASS_H
#define XCLASS_H

class xClass {
private:
	int* data;		// private, (pointer to) an integer data array
	int size;		// private, size of the data array

public:
	// (1) constructor, to set size to the given length, allocate memory 
	// for the data array to the given size, and set all elements of the 
	// array to random numbers between 0 and max_val-1 inclusive
	xClass(int length, int max_val);
	// (2) destructor, to free the memory allocated for the data array
	~xClass();

	// (3) function, to print all numbers in the data array;
	void print_data() const;
	// (4) function, to return the average of the numbers in the data array
	int ave_data() const;
	// (5) function, to return the number at index i of the data array
	int data_at(int i) const;
	// (6) function, to return the count of the numbers in the data array that fall  
	// within the range min-max inclusive
	int range_data(int min, int max) const;

	// (7) copy constructor, used to initialise one object by another 
	// e.g. xClass a = b, where object a is initialised by object b
	xClass(const xClass& b);

	// (8) operator +=, applied to two objects e.g. a += b
	// the resultant a will have a lengthened data array, holding the original 
	// a's data followed by the b's data
	void operator+=(const xClass& b);
};

#endif // !XCLASS_H

