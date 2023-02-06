#include <bits/stdc++.h>

using namespace std;

int main()
{

    int a[] = {1, 2, 2, 2, 3, 4};
    int n = 6;
    int k = 2;
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        int presentsize = freq.size();
        // if new element came and size of map is already equals to k than break
        if (freq[a[i]] == 0 && presentsize == k)
            break;
        freq[a[i]]++;
    }
    vector<pair<int, int>> ans;
    map<int, int>::iterator it;

    // make pair of element and its freq and push it in a vector of pair
    for (it = freq.begin(); it != freq.end(); it++)
        if (it->second != 0)
            ans.push_back({it->second, it->first});

    // sort the vector
    sort(ans.begin(), ans.end(), greater<pair<int, int>>());

    vector<pair<int, int>>::iterator i;

    for (i = ans.begin(); i != ans.end(); i++)
        cout << i->second << " " << i->first << endl;

    return 0;
}