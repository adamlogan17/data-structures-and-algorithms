#include "List.h"
#include <iostream>

using namespace std;

int binarySearch(List<int>* plist, int first, int last, int key)
{
    // base case - not found
    if (first > last) return -1;

    // recursive case
    int mid = (first + last) / 2;
    int val = plist->get(mid);
    if (val == key)
        return mid;
    else if (key < val)
        return binarySearch(plist, first, mid - 1, key);
    else
        return binarySearch(plist, mid + 1, last, key);
}

int main()
{
    cout << "Input: (1) List size N (2) Key" << endl;
    int N, key;
    cin >> N >> key;

    // test binary search
    List<int>* plist = new List<int>;
    for (int i = 0; i < N; i++)
        plist->insert_end(i);

    cout << "Position of occurrence = " << binarySearch(plist, 0, plist->size() - 1, key) << endl;

    // test linear serach using setp_first & get_next
    int p = -1;
    plist->setp_first();
    for (int i = 0; i < plist->size(); i++)
        if (plist->get_next() == key) {
            p = i;
            break;
        }
    cout << "Position of occurrence = " << p << endl;

    // test linear search using get
    p = -1;
    for (int i = 0; i < plist->size(); i++)
        if (plist->get(i) == key) {
            p = i;
            break;
        }
    cout << "Position of occurrence = " << p << endl;

    delete plist;
    return 0;
}