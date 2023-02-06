#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<vector<int>> time;

    for (int i = 0; i < n; i++)
    {

        int start, end;
        cin >> start >> end;

        time.push_back({start, end});
    }

    // sorting the vector accroding to the ending time
    sort(time.begin(), time.end(), [&](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });

    // initally take first activity which ends first
    int take = 1;
    int end = time[0][1];
    // end is quals to ending time of first activity
    for (int i = 1; i < n; i++)
    {

        // start time of next activity and end time of first activity dont overlap than do it
        if (time[i][0] >= end)
        {
            take++;
            end = time[i][1]; // update end time
        }
    }

    cout << take << endl;
    return 0;
}