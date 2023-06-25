#include <iostream>
#include <fstream>
#include <ctime>
#include "List.h"

using namespace std;

// maxmimum size of array list e.g. 2^18
constexpr int Max_ListSize = 262144;

// insert an item at position p, into an array list with size items pointed by List 
template<typename T>
T* insert(T* list, int& size, int p, T item)
{
	if (p < 0 || p > size) {
		cout << "Unable to insert at " << p << endl << endl;
		return NULL;
	}
	else if (size >= Max_ListSize) {
		cout << "List full" << endl << endl;
		return NULL;
	}

	for (int i = size - 1; i >= p; i--)
		list[i + 1] = list[i];
	list[p] = item;
	size++;

	return list;
}

// remove an item at position p, from an array list with size items pointed by List
template <typename T>
T remove(T* list, int& size, int p)
{
	if (p >= 0 && p < size) {
		T item = list[p];
		for (int i = p + 1; i < size; i++)
			list[i - 1] = list[i];
		size--;
		return item;
	}
	else {
		cout << "Unable remove at position " << p << endl;
		exit(1);
	}
}

// isWord
bool isWord(string item)
{
	int i = 0;
	while (i < item.size() && (isupper(item[i]) || islower(item[i])))
		i++;
	return (i > 0 && i == item.size());
}

// time deletion operations
int main()
{
	/* arraylist */
	string* alist = new string[Max_ListSize];
	int size = 0;

	// load corpus
	ifstream fi("corpus.txt");
	string item;
	int p = 0;
	while (fi >> item) {
		if (isWord(item))
			insert(alist, size, p++, item);
	}
	fi.close();

	// time deletion
	time_t startTime = clock();
	for (int i = 0; i < 100; i++) {
		int p = 0;		// p = size/2, size-1 for delete at middle, end
		remove(alist, size, p);
	}
	time_t endTime = clock();
	cout << (endTime - startTime) / 1000.0 << endl;

	/* linked list */
	List<string> llist;

	// load corpus
	fi.open("corpus.txt");
	while (fi >> item) {
		if (isWord(item))
			llist.insert_end(item);
	}
	fi.close();

	// time deletion
	startTime = clock();
	for (int i = 0; i < 100; i++) {
		int p = 0;		// p = llist.size()/2, llist.size()-1 for delete at middle, end
		llist.remove(p);
	}
	endTime = clock();
	cout << (endTime - startTime) / 1000.0 << endl;

	return 0;
}

int main2()
{
	// 1. use a linked list - llist, to store corpus.txt
	List<string> llist;

	ifstream fi("corpus.txt");
	string item;
	while (fi >> item) {
		if (isWord(item))
			llist.insert_end(item);
	}
	fi.close();

	// 2. traverse llist using get(int p) to each position in the list to find the longest word
	string word = llist.get(0);
	int wordLen = word.size();
	for (int p = 1; p < llist.size(); p++) {
		item = llist.get(p);
		if (item.size() > wordLen) {
			wordLen = item.size();
			word = item;
		}
	}
	cout << "The longest word is: " << word << endl;

	// 3. traverse llist using set_first & then get_next to each position in the list to find the longest word
	llist.setp_first();
	word = llist.get_next();
	wordLen = word.size();
	for (int p = 1; p < llist.size(); p++) {
		item = llist.get_next();
		if (item.size() > wordLen) {
			wordLen = item.size();
			word = item;
		}
	}
	cout << "The longest word is: " << word << endl;

	return 0;
}

int main1_()
{
	/* array list */
	// 1. generate a string array list, alist, of Max_ListSize
	//    initialise size of the list, size, to 0

	// 2. open the corpus file: ifstream fi("corpus.txt");
	//    read each item in the file & insert each proper word at the end of alist 
	//    close the file: fi.close();

	// 3. time deletion operations for alist
	//    e.g. remove 100 words at the front, middle or end of alist

	/* linked list */
	// 1. declare a string-type List object llist

	// 2. open the corpus file: fi.open("corpus.txt");
	//    read each item in the file & insert each proper word at the end of llist 
	//    close the file: fi.close();

	// 3. time deletion operations for llist
	//    e.g. remove 100 words at the front, middle or end of llist

	return 0;
}
