#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define ff first
#define ss second
#define repit(it, a, b) for (it = a; it != b; it++)
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int n;
    cin >> n;
    int a[n];

    rep(i, 0, n)
            cin >>
        a[i];

    mii mp;
    int prefsum = 0;

   //store all prefix sum in map
    rep(i, 0, n)
    {
        prefsum += a[i];
        mp[prefsum]++;
    }
    mii ::iterator it;
    int ans = 0;
    // travers through map 
    repit(it, mp.begin(), mp.end())
    {
        // count m^C2 and add in ans
        int c = it->ss;
        ans += (c * (c - 1)) / 2;

        // if prefix sum=0 add its all frequncy too
        if (it->ff == 0)
            ans += it->ss;
    }
    cout << ans << endl;
    return 0;
}