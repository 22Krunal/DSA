#include <bits/stdc++.h>

using namespace std;
bool isBipartite = false;
// try to unsolve error
// bool dfs(int src, vector<vector<int>> &adj, vector<int> &color, int curr)
// {
//          if(color[src]!=-1&&curr!=color[src])
//          return false;
//          if(color[src]==curr)
//          return true;
//         color[src]=curr;

//     for (auto it : adj[src])
//     {
//             return dfs(it, adj, color, curr xor 1);

//     }

//     return false;
// }

void bipartite(int src, vector<vector<int>> &adj, vector<int> &color, int curr)
{
    if (color[src] != -1 && curr != color[src])
    {
        isBipartite = false;
        return;
    }
    else if (curr == color[src])
        isBipartite = true;
    else
    {
        color[src] = curr;
        for (auto it : adj[src])
        {
            bipartite(it, adj, color, curr xor 1);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {

        if (color[i] == -1)
        {
            // isBipartite = dfs(i, adj, color, 0);
            bipartite(i, adj, color, 0);
        }
    }
    if (isBipartite)
        cout << "It is Bipartite graph" << endl;
    else
        cout << "It is not Bipartite graph" << endl;

    return 0;
}