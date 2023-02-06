#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
bool vis[N];    // to keep track of visited nodes
vector<int> adj[N]; // 2d martix for adjcency list
int main()
{

    for (int i = 0; i < N; i++) // first mark all nodes as unvisited
        vis[i] = 0;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    { // store the adjcency list
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);         // start from node 1
    vis[1] = true; // mark it as visited
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();

        for (auto it : adj[tmp])
        { // adjcent node of current node
            if (!vis[it])
            { // if it is not visted than push it in queue and mark visited
                vis[it] = true;
                q.push(it);
            }
        }
        cout << tmp << endl; // print current node
    }
    return 0;
}