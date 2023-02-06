#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p, dist; // initall flue amount and dist from the twon
    cin >> p >> dist;
    int n; // total number of stops in the way
    cin >> n;

    int *stops = (int *)malloc(sizeof(int) * n); // distance of stops from twon
    int *flue = (int *)malloc(sizeof(int) * n);  // flue they have

    for (int i = 0; i < n; i++)
        cin >> stops[i];
    for (int i = 0; i < n; i++)
        cin >> flue[i];

    vector<vector<int>> stations;
    for (int i = 0; i < n; i++)
        stations.push_back({(dist - stops[i]), flue[i]});
    free(stops);
    free(flue);

    sort(stations.begin(), stations.end(), [&](vector<int> &a, vector<int> &b)
         { return a[0] < b[0]; });

    int x = p, hold = 0;
    bool flag = false;

    priority_queue<int, vector<int>> maxheap;
    for (int i = 0; i < n; i++)
    {

        if (x >= dist) // we reached at twon than flag is true
        {
            flag = true;
            break;
        }
        if (stations[i][0] <= x) // push fuel of stations that we cross in maxheap
        {
            maxheap.push(stations[i][1]);
        }
        else // fuel is empty than add the max fuel that we cross than update count
        {
            x += maxheap.top();
            maxheap.pop();
            hold++;
        }
    }
    if (flag)
        cout << hold << endl;
    else
        cout << "-1" << endl;
    return 0;
}