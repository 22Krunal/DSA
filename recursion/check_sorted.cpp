// It's working but a bit slow
#include<bits/stdc++.h>
using namespace std;

bool isSorted(int a[],int n){
    if(n==0)
    return true;
    if(n>0&&a[n]>a[n-1])
    return isSorted(a,n-1);
    else
    return false;
}
int main(){
    int a[]={1,2,3,4,5,6,7};
    
cout<<isSorted(a,7);
return 0;
}