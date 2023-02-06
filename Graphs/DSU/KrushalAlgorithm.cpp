#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 6;

vector<int> parent(N);
vector<int> sz(N);

void make_set(int val)
{
    parent[val] = val;
    sz[val] = 1;
}
int find_set(int val)
{
    if (val == parent[val])
        return val;
    return parent[val] = find_set(parent[val]);
}
void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b)
        return;
    if (sz[a] < sz[b])
        swap(a, b);
    parent[b] = a;
    sz[a] += b;
}
int main()
{
    for(int i=0;i<N;i++)
    make_set(i);

    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    int cost=0;
    cout<<"Edges in MST:";
    for(auto it:edges){
     int w=it[0];
     int u=it[1];
     int v=it[2];

     int x=find_set(u);
     int y=find_set(v);
      
      if(x==y){
          continue;
      }else{
          cout<<u<<" "<<v<<endl;
          cost+=w;
          union_set(u,v);
      }


    }
    cout<<"Cost of MST:->"<<cost<<endl;
    return 0;
}