#include <iostream>
#include "iStack.h"

using namespace std;

int main()
{
	// build a stack of integers between 0 - 9
	iStack is;
	for (int n = 0; n < 100; n++)
		is + rand() % 10;	// OR is.push(rand() % 10);

	// print the stack
	is.print();

	// locate the 1st occurrence of key '5' (may be included) and '20' (not included)
	cout << is.search(5) << endl;
	cout << is.search(20) << endl;

	/* REPEAT THE TEST USING DYNAMIC OBJECT */
	iStack* pis = new iStack;
	for (int n = 0; n < 100; n++)
		*pis + rand() % 10;	// OR pis->push(rand() % 10);

	pis->print();

	cout << pis->search(5) << endl;
	cout << pis->search(20) << endl;

	delete pis;

	return 0;
}
