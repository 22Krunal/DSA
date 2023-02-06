#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;
const int INFI = 1e9;
int main()
{

    int n, m;

    cin >> n >> m;

    vector<int> dist(n + 1, INFI);               // to keep track of distance from source node
    vector<vector<pair<int, int>>> graph(n + 1); // adjcency list with weight
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cin >> source;
    dist[source] = 0; // distance of source to source
    set<pair<int, int>> s;
    s.insert({0, source});

    while (!s.empty())
    {

        auto x = *(s.begin());
        s.erase(x);
        for (auto it : graph[x.second])
        {
            // if current source distance is greater than distance of currnode+distance of its neighbour
            //  if dis(0,4) > dis(0,3)+dis(3,4)
            if (dist[it.first] > dist[x.second] + it.second)
            {
                s.erase({dist[it.first], it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first], it.first});
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (dist[i] < INFI)
            cout << dist[i] << " ";
        else
            cout << -1 << " ";
    }
    return 0;
}