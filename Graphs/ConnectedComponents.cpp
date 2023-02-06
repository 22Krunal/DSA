#include <bits/stdc++.h>

using namespace std;

int dfs(int src, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[src] = true;
    cout << src << " ";
    int ans = 1; // initialize with 1 because component hase min size of 1
    for (auto it : adj[src])
    {
        if (!visited[it])
            ans += dfs(it, adj, visited);
    }
    return ans; // return size of the component
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
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n, false);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << "component :";
            ans.push_back(dfs(i, adj, visited));
            cout << endl;
        }
    }
    long long int res = 0;
    for (auto it : ans)
        res += it * (n - it);

    cout << "Ways to form a group from two different group's memeber:" << (res / 2) << endl;
    return 0;
}