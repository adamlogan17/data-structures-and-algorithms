#ifndef SSARRAY_H
#define SSARRAY_H

#include <iostream>

template<typename T>
class sarray {
public:
	sarray(int size);
	~sarray();

	T& operator[](int i);

private:
	int size;
	T* data;
};

template<typename T>
sarray<T>::sarray(int size)
	: size(size)
{
	if (size > 0) data = new T[size];
	else {
		std::cout << "illegal array size = " << size << std::endl;
		exit(1);
	}
}

template<typename T>
sarray<T>::~sarray()
{
	delete[] data;
}

template<typename T>
T& sarray<T>::operator[](int i)
{
	if (i < 0 || i >= size) {
		std::cout << "index " << i << " is out of bounds." << std::endl;
		exit(1);
	}
	return data[i];
}

#endif
