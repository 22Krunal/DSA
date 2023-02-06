#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
bool vis[N];
vector<int> adj[N];

void dfs(int node)
{
    vis[node] = true;

    cout << node << endl; // preorder
    for (auto it : adj[node])
    {

        if (!vis[it])
            dfs(it);
    }
    // cout<<node<<endl; //postorder
}
int main()
{

    for (int i = 0; i < N; i++)
        vis[i] = false;

    int n, m;
    cin >> n >> m;

    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    // stack<int>st;
    // st.push(1);
    // vis[1]=true;
    // while(!st.empty()){
    //     int tmp=st.top();
    //     st.pop();

    //     for(auto it:adj[tmp]){

    //        if(!vis[it]){
    //            vis[it]=true;
    //            st.push(it);
    //        }
    //     }
    //   cout<<tmp<<endl;
    // }
    dfs(1);
    return 0;
}