#include <bits/stdc++.h>

using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> stack)
{
    stack[src] = true;
    if (!visited[src])
    {
        visited[src] = true;

        for (auto it : adj[src])
        {

            if (!visited[it] && isCycle(it, adj, visited, stack))
                return true;
            if (stack[it])
                return true;
        }
    }

    stack[src] = false;
    return false;
}
int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // u--->v
        adj[u].push_back(v);
    }
    vector<bool> stack(n, false);
    vector<bool> visited(n, false);
    bool cycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[n] && isCycle(i, adj, visited, stack))
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