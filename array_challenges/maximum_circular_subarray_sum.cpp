// case 1 {-1,4,-6,7,5,-4} maxsum=12 {7,5}
// case 2 {4,-4,6,-6,10,-11,12} maxsum=22 {12,4,-4,6,-6,10}
// for case 1 we can esaily calculate by kadane's algorithm
// for case 2 we have to check another possiblity also because it is circular 
// for this question brute force approch is to apply nested loop :o(n^2)
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
    int wrap,nowrap,sum=0;
     wrap=kadane(a,n);    //no need for rafting 
     for(int i=0;i<n;i++){  //change sign of all elements
         sum+=a[i];
         a[i]=-a[i];
     }
     nowrap=sum+kadane(a,n);  //substracting kadanes sum which is no countributing elements
     cout<<max(wrap,nowrap)<<endl;
    return 0;
}