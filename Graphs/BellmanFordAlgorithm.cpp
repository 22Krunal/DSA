#include <bits/stdc++.h>

using namespace std;

const int INFI = 1e9;
int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges; //{u,v,w}
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int source;
    cin >> source;
    vector<int> dist(n, INFI);
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++)
    {

        for (auto it : edges) // all edges be updated if needed
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    for (auto dis : dist)
        cout << dis << " ";
    cout << endl;
    return 0;
}