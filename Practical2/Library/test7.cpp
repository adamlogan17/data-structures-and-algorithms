#include "myLib.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Set the char-string size: ";
	int size = 0;
	cin >> size;
	cout << "Set key (a-z) to be searched: ";
	char key = 0;
	cin >> key;

	// allocate the array
	char* pchs = new char[size];
	if (pchs != NULL) {
		// populate the array with random alphabetic letters - lower case
		for (int n = 0; n < size; n++) {
			pchs[n] = 97 + rand() % 26;
			cout << pchs[n] << " ";
		}
		cout << endl;

		// search
		cout << "Occurrences = " << search(pchs, size, key) << endl;
	}
	delete[] pchs;

	return 0;
}
