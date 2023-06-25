#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

// test print, search
int main2()
{
	// build a char stack with random a-z
	Stack<char> chs;
	for (int i = 0; i < 100; i++)
		chs.push(97 + rand() % 26);
	chs.print();

	// locate the 1st occurrence of key 'k' (may be included) and '@' (not included)
	cout << chs.search('k') << endl;
	cout << chs.search('@') << endl;

	/* REPEAT THE TEST USING DYNAMIC OBJECT */
	Stack<char>* pchs = new Stack<char>;
	for (int i = 0; i < 100; i++)
		pchs->push(97 + rand() % 26);
	pchs->print();

	cout << pchs->search('k') << endl;
	cout << pchs->search('@') << endl;

	delete pchs;

	return 0;
}

// test operator ==
int main()
{
	// stack a
	Stack<string> a;
	for (int i = 0; i < 10; i++)
		a.push(to_string(rand() % 65536));

	// stack b is the same as stack a by using copy constructor
	Stack<string> b = a;

	if (a == b)
		cout << "Two stacks are identical" << endl;
	else
		cout << "Two stacks are different" << endl;

	// stack c has the same number of items as stack a but has different items
	Stack<string> c;
	for (int i = 0; i < 10; i++)
		c + to_string(rand() % 65536);

	if (a == c)
		cout << "Two stacks are identical" << endl;
	else
		cout << "Two stacks are different" << endl;

	return 0;
}
