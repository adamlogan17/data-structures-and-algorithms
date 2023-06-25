#include <iostream>
#include <ctime>
using namespace std;

// (1) testing if an array is sorted
bool isSorted(int* a, int N)
{
	for (int i = 0; i < N - 1; i++)
		if (a[i] > a[i + 1])
			return false;
	return true;
}

// (2) bubble sort
void bubbleSort(int* a, int N)
{
	bool sorted;
	do {
		sorted = true;
		for (int i = 0; i < N - 1; i++)
			// out of order - swap a[i] and a[i+1]
			if (a[i] > a[i + 1]) {
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				sorted = false;
			}
	} while (sorted == false);
}

// (3) quick sort
void quickSort(int* a, int first, int last)
{
	// partition
	int i = first, j = last;
	int pivot = a[(first + last) / 2];  // not the median!

	while (i <= j) {
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;

		if (i <= j) {  // swap
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++; j--;
		}
	}

	// recursion
	if (first < i - 1) quickSort(a, first, i - 1);
	if (i < last) quickSort(a, i, last);
}

int main()
{
	cout << "Array size N = ";
	int N = 0;
	cin >> N;

	// (1) test if an array is sorted
	int* a = new int[N];
	for (int i = 0; i < N; i++)
		a[i] = 3 * i + 1;		// an example of sorted array
	cout << "Array is sorted: " << isSorted(a, N) << endl << endl;

	for (int i = 0; i < N; i++)
		a[i] = rand() % 1000;	// an example of unsorted array
	cout << "Array is sorted: " << isSorted(a, N) << endl << endl;

	// backup unsorted a in b for comparing Bubble Sort & Quick Sort 
	int* b = new int[N];
	for (int i = 0; i < N; i++) b[i] = a[i];

	// (2) test bubble sort & timing
	cout << "Test bubble sort" << endl;
	clock_t begin = clock();
	bubbleSort(a, N);
	clock_t end = clock();
	double elapsed = double(end - begin);
	cout << "Time taken to sort " << N << " values = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl;

	cout << "Array is sorted: " << isSorted(a, N) << endl << endl;

	// (3) test quick sort & timing
	cout << "Test quick sort" << endl;
	begin = clock();
	quickSort(b, 0, N - 1);
	end = clock();
	elapsed = double(end - begin);
	cout << "Time taken to sort " << N << " values = " << elapsed << " ms = "
		<< elapsed / 1000.0 << " s" << endl;

	cout << "Array is sorted: " << isSorted(b, N) << endl << endl;

	delete[] a;
	delete[] b;
	return 0;
}