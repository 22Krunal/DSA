// Find subarray in array which has maximum sum
// kadane's algorithm
#include<bits/stdc++.h>
using namespace std;
int kadane(int a[],int n){
       int current=0,maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        current+=a[i];
        if(current<0){
            current=0;
        }
        maxsum=max(current,maxsum);
    }
    return maxsum;
}
int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    
cout<<kadane(a,n)<<endl;
return 0;
}