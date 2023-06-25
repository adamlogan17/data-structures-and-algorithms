#include <iostream>
#include <ctime>
#include "List.h"

using namespace std;

int coun1(List<int>& ll, int key)
{
	clock_t begin = clock();

	// operation being timed
	int count = 0;
	for (int p = 0; p < ll.size(); p++)
		if (ll.get(p) == key)
			count++;

	clock_t  end = clock();

	double elapsed = double(end - begin);
	cout << "Time taken with N = " << ll.size() << " is " << elapsed << " ms"
		<< " = " << elapsed / 1000.0 << " s" << endl;

	return count;
}

int coun2(List<int>& ll, int key)
{
	clock_t begin = clock();

	// operation being timed
	ll.setp_first();
	int count = 0;
	for (int p = 0; p < ll.size(); p++)
		if (ll.get_next() == key)
			count++;

	clock_t  end = clock();

	double elapsed = double(end - begin);
	cout << "Time taken with N = " << ll.size() << " is " << elapsed << " ms"
		<< " = " << elapsed / 1000.0 << " s" << endl;

	return count;
}

int main()
{
	cout << "Data size N = ";
	int N;
	cin >> N;

	// the list
	List<int> iList;
	for (int i = 0; i < N; i++)
		iList.insert_end(rand() % 100);

	// test coun1
	cout << "Count 1 = " << coun1(iList, 0) << endl;

	// test count2
	cout << "Count 2 = " << coun2(iList, 0) << endl;

	return 0;
}