// you have to print sum of all subarrays
// every subarray is subsequence but not every subsequence is not subarray
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++){
        int sum=a[i];
        cout<<sum<<" ";
        for(int j=i+1;j<n;j++){
           sum+=a[j];
           cout<<sum<<" ";
        }
        cout<<endl;
    }
cout<<"";
return 0;
}