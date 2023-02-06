#include<bits/stdc++.h>


using namespace std;

const int N = 1e5;
// int parent[N];
vector<int> adj[N];

int parent[N];
int sz[N];
// implimenting DSU

void makeSet(int val){
    parent[val] = val;
    sz[val] = 1;
}

int findSet(int val){
    
    if(parent[val] == val){
        return val;
    }

    return parent[val] = findSet(parent[val]);
}

void unionSet(int x, int y){
    int a = findSet(x);
    int b = findSet(y);

    if(a == b){
        return ;
    }

    if(sz[a] < sz[b]){
        swap(a,b);
    }

    parent[b] = a;
    sz[a] += sz[b];
}

bool isBiapartite(vector<vector<int>> & adj,int n){
    vector<int> color(n,0); // 0-> red 1->blue
}
int main(){
    int n,m; cin >> n >> m;
    
    // keep track of visited nodes
    vector<int> vis(n,0);

    for(int i=0; i<m; i++){
        int u,v; cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // BFS
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    vector<int> res(n);
    while(!q.empty()){
        int x  = q.front();
        q.pop();
        res.push_back(x);
        for(auto it : adj[x]){
            if(!vis[it]){
            // res.push_back(it);
            vis[it] = 1;
            q.push(it);
            }
        }
    }
  // DFS 
  stack<int> st;
  vector<int> visited(n,0);
  st.push(0);
  visited[0] = 1;
  vector<int> ans(n);
  while(!st.empty()){
    int x = st.top();
    st.pop();
    ans.push_back(x);
    for(auto it : adj[x]){
        if(!visited[it]){
            visited[it] = 1;
            st.push(it);
        }
    }
    visited[x] = 1;
  } 
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}