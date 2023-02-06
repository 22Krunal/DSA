// we may change upto k values to make longest subarray of ones
// in this we keep couting zeros in subarray till count exceed the value of k than we remove some zeros 
// till count is less than k
#include<bits/stdc++.h>

using namespace std;
void max_one(vector <int> a,int k){
    int n=a.size();
    int ans=0,zcount=0,j=0;
    for(int i=0;i<n;i++){
       if(a[i]==0)
       zcount++;
       while (zcount>k)
       {
           if(a[j]==0)
           zcount--;
           j++;
       }
       ans=max(ans,i-j+1);
       
    }
    cout<<ans<<endl;

}
int main(){
    vector <int > a={0,1,1,1,0,0,1,0,1,0,1,1,1};
    int k;
    cin>>k;
    max_one(a,k);
    return 0;
}