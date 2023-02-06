#include <bits/stdc++.h>

using namespace std;

const int N=1e5+6;
vector<int>g[N];
void primsMST(int node,vector<bool>&visited){

    visited[node]=true;

    for(auto it:g[node]){

        if(!visited[it[0]]){
            primsMST(it[0],visited);
        }
        else{
            
        }
    }

}
int main()
{


      int n,m;
      cin>>n>>m;


      for(int i=0;i<m;i++){
          int u,v,w;
          cin>>u>>v>>w;
          g[u].push_back({v,w});
          g[v].push_back({u,w});
      }
      vector<bool>visited(n,false);
      primsMST(0,visited);
        return 0;
}