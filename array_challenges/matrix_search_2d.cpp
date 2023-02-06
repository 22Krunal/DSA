// all rows and columns are sorted
// This is optimized version to search for element in 2d array
// brute force approch is to travers through all elements
#include<bits/stdc++.h>
using namespace std;
int main(){
 int k;
 cin>>k;
 int n=5;
 int a[n][n]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
 int r=0,c=n-1;
 while(c>=0&&r<n){
     if(a[r][c]==k)
     cout<<"found"<<"\n";
     if(a[r][c]>k)
     c--;
     else
     r++;
 }
cout<<"";
return 0;
}