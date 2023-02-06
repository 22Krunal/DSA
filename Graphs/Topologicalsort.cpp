#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // edje u--->v
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)  //push all nodes which have zero indegree
        if (indeg[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (auto it : adj[node]) //decrease indegree of element which is connected to current node
        {
            indeg[it]--;
            if (indeg[it] == 0)  //if indegree becomes zero push it in a queue
                q.push(it);
        }
    }
    cout << endl;
    return 0;
}