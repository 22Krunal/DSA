#include<bits/stdc++.h>


using namespace std;

const int N = 1e3;
int parent[N];
int sz[N];

void make_set(int val){
    parent[val] = val;
    sz[val] = 1;
}
int find_set(int val){
    if(parent[val] == val){
        return val;
    }
    return parent[val] = find_set(parent[val]);
}
void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if(a == b){
        return ;
    }
    if(sz[b] > sz[a]){
        swap(a,b);
    }

    parent[b] = a;
    sz[a] += sz[b];
    return ;
}
int main(){
    
    int n ,m; cin >>n >> m;

    vector<int , pair<int,int > > edges(n+1);

    for(int i=0; i<n; i++){
        int u,v,w; cin >> u >> v >> w;

        edges[u].first = v;
        edges[u].second = w;
    }



    

    cout<<"";
    return 0;
}