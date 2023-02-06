#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    int val[n], wei[n];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n; i++)
        cin >> wei[i];
    int w;
    cin >> w;
    vector<vector<int>> value;

    // count value per unit and store it in a vector
    for (int i = 0; i < n; i++)
    {

        int temp = val[i] / wei[i];
        value.push_back({wei[i], temp});
    }

    sort(value.begin(), value.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    // to arrange it in a decending order
    reverse(value.begin(), value.end());

    int i = 0, profit = 0;
    while (w > 0)
    {
        // if total weight is less than weight we can put than add all
        if (value[i][0] <= w)
        {
            w -= value[i][0];
            profit += (value[i][0] * value[i][1]);
        }
        else // add till capacity is full
        {

            profit += w * value[i][1];
            w = 0;
        }
        i++;
    }
    cout << profit << endl;
    return 0;
}