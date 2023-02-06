#include<bits/stdc++.h>
#include<vector>
using namespace std;
int find(vector <pair<int,int>> s,int index){

}
int main(){
    int n,ans=0;
    cin>>n;
    vector <pair<int,int>> t;
    vector<pair<int,int>> r;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        t.push_back(make_pair(a,i));
        r.push_back(make_pair(b,i));
    }
       t.sort(t.begin(),t.end());
       r.sort(r.begin(),t.end());
for(int i=0;i<n;i++){
    if(i%2==0){
        ans+=t.front();
        t.erase(i);
    }
    else
    {
           ans-=r.front();
          r.erase(find(r,i));

    }
}
    return 0;
}

