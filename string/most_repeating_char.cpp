#include <bits/stdc++.h>
using namespace std;
int freq[26];
int main()
{
    string s;
    cin >> s;
    char k;
    int max = INT_MIN;
    for (int i = 0; i < s.length(); i++)
    {
        int temp = (int)s[i] - 97;
        // cout<<temp<<" ";
        freq[temp] += 1;
        if (max < freq[temp])
        {
            max = freq[temp];
            k = s[i];
        }
    }

    cout << k;
    return 0;
}