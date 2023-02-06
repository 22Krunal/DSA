#include <bits/stdc++.h>

using namespace std;

int main()
{

    int a[] = {2, 2, 2, 1, 1, 4, 3, 4};
    map<int, int> freq;

    // counting freq of all elements
    for (int i = 0; i < 8; i++)
    {
        freq[a[i]]++;
    }

    // iterator for to travers in map
    map<int, int>::iterator it;

    for (it = freq.begin(); it != freq.end(); it++)
        cout << it->first << " -> " << it->second <<endl;

    return 0;
}