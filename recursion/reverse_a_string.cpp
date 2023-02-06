#include <bits/stdc++.h>
using namespace std;
void Reverse(string s, int n, string ans)
{
    if (n == 0)
    {
        cout << ans << endl;
        return;
    }
    ans += s[n - 1];

    Reverse(s, n - 1, ans);
}
int main()
{
    string s;
    cin >> s;
    Reverse(s, s.length(), "");

    return 0;
}