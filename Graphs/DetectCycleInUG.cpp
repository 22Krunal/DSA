#include <bits/stdc++.h>

using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &vis, int parent)
{
    vis[src] = true;
    for (auto it : adj[src])
    {
        if (it != parent) //this is not parent and it is alredy been visited than cycle is present
        {
            if (vis[it])
                return true;
            if (!vis[it] && isCycle(it, adj, vis, src))
                return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && isCycle(i, adj, vis, -1))
        {
            cycle = true;
        }
    }
    if (cycle)
        cout << "Cycle is Present in the graph" << endl;
    else
        cout << "No Cycle is Present in the graph" << endl;
    return 0;
}