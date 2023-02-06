#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 6;

// parent and size vector for implementing DSU
vector<int> parent(N);
vector<int> sz(N);

void make_set(int val) // making a set so every element is parent of its own
{

    parent[val] = val;
    sz[val] = 1;
}
int find_set(int val) // find the parent of set and set new parent as parent of parent
{
    if (val == parent[val])
        return val;
    return parent[val] = find_set(parent[val]);
}
void union_set(int a, int b) // if from different set than union rank wise
{
    a = find_set(a);
    b = find_set(b);
    if (a == b)
        return;
    if (sz[a] < sz[b])
        swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
}
int main()
{
    for (int i = 0; i < N; i++)
        make_set(i);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    bool isCycle = false;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        int x = find_set(u);
        int y = find_set(v);

        if (x == y)
            isCycle = true;
        else
            union_set(u, v);
    }
    if (isCycle)
        cout << "Cycle is Present in the graph" << endl;
    else
        cout << "No,Cycle is present in the graph" << endl;
    return 0;
}