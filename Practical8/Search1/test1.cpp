#include <vector>
#include <string>
#include <iostream>

using namespace std;

void print_duplicate(int* pi1, int N1, int* pi2, int N2)
{
    for (int i = 0; i < N1; i++) {
        bool found = false;
        for (int j = 0; j < N2; j++)
            if (pi1[i] == pi2[j]) {
                found = true;
                break;
            }
        if (found)
            cout << pi1[i] << endl;
    }
}

// test print_duplicate
int main()
{
    cout << "Type: N1 N2" << endl;
    int N1, N2;
    cin >> N1 >> N2;

    int* pi1 = new int[N1];
    int* pi2 = new int[N2];
    if (pi1 && pi2) {
        for (int i = 0; i < N1; i++)
            pi1[i] = rand() % 10000;
        for (int i = 0; i < N2; i++)
            pi2[i] = rand() % 10000;

        print_duplicate(pi1, N1, pi2, N2);
    }
    delete[] pi1;
    delete[] pi2;

    cout << "The complexity of print_duplicate is " << "O(N1 * N2)" << endl;

    return 0;
}


// find index of 1st number not in [L, U]
int find_first_not_in_range(int* pi, int N, int L, int U)
{
    for (int n = 0; n < N; n++)
        if (!(pi[n] >= L && pi[n] <= U))
            return n;
    return -1;
}

// test find_first_not_in_range
int main1()
{
    cout << "Type: (1) array size N (2) lower bound (3) upper bound " << endl;
    int N, L, U;
    cin >> N >> L >> U;

    int* pi = new int[N];
    if (pi) {
        // create the array with N random numbers in the range 0-100
        for (int i = 0; i < N; i++)
            pi[i] = rand() % 101;

        // print the array
        for (int i = 0; i < N; i++)
            cout << pi[i] << " ";
        cout << endl;

        // search the array for the number
        cout << "The 1st number not in [" << L << ", " << U << "] is found at " << find_first_not_in_range(pi, N, L, U) << endl;
    }
    delete[] pi;

    // complexity statement
    cout << "The complexity of find_first_not_in_range is " << "O(N)" << endl;

    return 0;
}
