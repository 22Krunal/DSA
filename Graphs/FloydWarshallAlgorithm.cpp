#include <bits/stdc++.h>

using namespace std;

const int INFI=1e9;
int main()
{

  
    vector<vector<int>> graph = {{0, 5, INFI, 10}, {INFI, 0, 3, INFI}, {INFI, INFI, 0, 1}, {INFI, INFI,INFI, 0}};

    int n=graph.size();

    vector<vector<int>> dist=graph;
   
   for(int k=0;k<n;k++){
       for(int j=0;j<n;j++){

       for(int i=0;i<n;i++){

           if(dist[i][j]>dist[i][k]+dist[k][j])
           dist[i][j]=dist[i][k]+dist[k][j];
       }

       }
   }

   for(int i=0;i<n;i++){

   for(int j=0;j<n;j++)
   if(dist[i][j]<INFI)
   cout<<dist[i][j]<<" ";
   else
   cout<<"INFI"<<" ";

   cout<<endl;
   }
    return 0;
}