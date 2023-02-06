//find number of distinct line from given points
// (1,0),(1,1),(0,1),(0,0)->four distict lines 2 horizontal 2 vertical
// 0<x,y<n
// error
#include<bits/stdc++.h>
using namespace std;
int lines(int a[],int n,int x[],int l){
    for(int i=0;i<l;i++)
    x[i]=0;
    int max=0;
    for(int i=0;i<n;i++){
        cout<<x[i]<<" ";
        int j=a[i];
        if(a[i]>=0)
        x[j]+=1;
        cout<<j<<" "<<x[j]<<" ";
        max=max>x[a[i]]?max:x[a[i]];
    }
    return max;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n],max1=0,max2=0;
        for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
            max1=max1>a[i]?max1:a[i];
            max2=max2>b[i]?max2:b[i];
        }
        int x[max1]={0},y[max2]={0},line=0;
           if(max1>0){
               line=n-lines(a,n,x,max1);
           }
           else{
               line=n;
           }
           if(max2>0){
               line+=n-lines(a,n,y,max2);
               
           }else{
               line+=n;
           }
           cout<<line<<endl;
           
           
    }
    return 0;
}