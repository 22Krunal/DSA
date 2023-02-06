// we are given a number k we have to find pair from array to sum k
// brute force approch is to check all the possible pairs o(n^2)
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    int low=0,high=n-1;
    while(low<high){
        if(a[low]+a[high]==k)
        {
            cout<<a[low]<<" "<<a[high]<<endl;
            return 0;
        }
        else if(a[low]+a[high]>k){
            high--;
        }
        else
        low++;
    }
    return 0;
}