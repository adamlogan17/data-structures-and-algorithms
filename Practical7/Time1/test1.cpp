#include <ctime>
#include <windows.h>
#include <iostream>

using namespace std;

// (1)
void testTiming(int N)
{
	clock_t begin = clock();

	// operation being timed
	Sleep(1);

	clock_t  end = clock();

	double elapsed = double(end - begin);
	cout << "Time taken with N = " << N << " is " << elapsed << " ms"
		<< " = " << elapsed / 1000.0 << " s" << endl;
}

// (2)
double findAverage(int* pi, int N)
{
	clock_t begin = clock();

	// operation being timed
	int total = 0;
	for (int n = 0; n < N; n++) {
		total += pi[n];
		Sleep(1);
	}
	double average = (double)total / (double)N;

	clock_t end = clock();

	double elapsed = double(end - begin);
	cout << "Time taken with N = " << N << " is " << elapsed << " ms"
		<< " = " << elapsed / 1000.0 << " s" << endl;

	return average;
}

// (3)
int find_countAverage(int* pi, int N)
{
	clock_t begin = clock();

	// operations being timed
	double average = findAverage(pi, N);
	int count = 0;
	for (int n = 0; n < N; n++) {
		if (pi[n] > (int)average)
			count++;
		Sleep(1);
	}

	clock_t end = clock();

	double elapsed = double(end - begin);
	cout << "Time taken with N = " << N << " is " << elapsed << " ms"
		<< " = " << elapsed / 1000.0 << " s" << endl;

	return count;
}

// (4)
int findFurthest(int* pi, int N)
{
	clock_t begin = clock();

	// operations being timed
	int* temp = new int[N];

	// find for each value pi[i] the closest other value
	for (int i = 0; i < N; i++) {
		int minDistance = MAXINT;
		for (int j = 0; j < N; j++) {
			Sleep(1);
			if (j != i)
				if (abs(pi[i] - pi[j]) < minDistance)
					minDistance = abs(pi[i] - pi[j]);
		}
		temp[i] = minDistance;
	}

	// find the value with the furthest closest other value
	int maxDistance = temp[0];
	int furthest = pi[0];
	for (int i = 1; i < N; i++)
		if (temp[i] > maxDistance) {
			Sleep(1);
			maxDistance = temp[i];
			furthest = pi[i];
		}
	delete[] temp;

	clock_t end = clock();

	double elapsed = double(end - begin);
	cout << "Time taken with N = " << N << " is " << elapsed << " ms"
		<< " = " << elapsed / 1000.0 << " s" << endl;

	return furthest;
}

int main()
{
	cout << "Data size N = ";
	int N;
	cin >> N;

	// (1) testTiming
	testTiming(N);

	// allocate & populate array
	int* pi = new int[N];
	if (!pi) return 1;
	for (int i = 0; i < N; i++)
		pi[i] = rand() % 100000;

	// (2) test find average - O(N)
	cout << "Average = " << findAverage(pi, N) << endl;

	// (3) test find average and count above average ~ O(2N) so O(N)
	cout << "How many above average = " << find_countAverage(pi, N) << endl;

	// (4) test findFurthest ~ O(N^2) + O(N) so O(N^2)
	cout << findFurthest(pi, N) << endl;

	delete[] pi;

	return 0;
}
