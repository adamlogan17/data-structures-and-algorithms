#include "List.h"
#include <iostream>

using namespace std;

// test list print, remove(int p1 int p2)
int main()
{
	// create an alphabet list
	List<char> chlist;
	for (int i = 0; i < 26; i++)
		chlist.insert_end(97 + i);

	// print chlist
	chlist.print();

	// remove nodes from 22-25
	if (chlist.remove(22, 25))
		chlist.print();

	// remove nodes from 0-3
	if (chlist.remove(0, 3))
		chlist.print();

	// remove nodes from 5-10
	if (chlist.remove(5, 10))
		chlist.print();

	return 0;
}
