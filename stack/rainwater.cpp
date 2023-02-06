#include<bits/stdc++.h>
using namespace std;
int rain_water(vector<int> a){
    int ans=0;
    stack <int> st;
    int n=a.size();
    st.push(a[0]);
    for(int i=0;i<n;i++){
      if(!st.empty()&&a[i]<=st.top()){
          st.push(a[i]);
      }else{
          while(!st.empty()&&a[i]>st.top()){
            ans+=a[i]-st.top();
            st.pop();
          }
          st.push(a[i]);
      }       
    }
    return ans;
}
int main(){
    vector<int> a={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rain_water(a);
    return 0;
}