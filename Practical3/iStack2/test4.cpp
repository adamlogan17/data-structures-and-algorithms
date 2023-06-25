#include <iostream>
#include <string>
#include "iStack.h"

using namespace std;

bool remove(iStack& is, int n)
{
	if (n < 0 || n >= is.size())
		return false;

	// move the top items above item number n to a temp stack
	iStack temp_is;
	while (is.size() > n + 1)
		temp_is + -is;	// OR temp_is.push(is.pop());

	// remove item n
	-is;

	// move items in temp_is back to is
	while (temp_is.size() > 0)
		is + -temp_is;

	return true;
}

// test remove
int main2()
{
	// a stack of 10 items
	iStack is;
	for (int n = 0; n < 10; n++)
		is + n;
	is.print();

	// remove item number 2
	if (remove(is, 2))
		is.print();

	// remove item number 11
	if (remove(is, 11))
		is.print();

	return 0;
}

int main()
{
	iStack is;

	string s;
	cout << "Enter sequence of numbers, ending with *" << endl;
	cin >> s;
	while (s != "*")
	{
		is.push(stoi(s));
		cin >> s;
	}

	while (is.size() > 0)
		cout << is.pop() << " ";
	cout << endl << endl;

	return 0;
}