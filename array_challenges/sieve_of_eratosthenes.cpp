// print the prime number in given range
// brute force approch is to check for all individul numbers
#include<bits/stdc++.h>
using namespace std;
void sieve_of_eratosthenes(int n){
    int a[n]={0}; //all numbers are unmarked intially
    for(int i=1;i<n;i++){
        if(a[i]!=1){
        int x=i+1;
        for(int j=x*x;j<n+1;j++){
            if(a[j-1]==0&&j%x==0)  //check if j is divisable by x then mark j-1 because index start from 0
                a[j-1]=1;
        }
        }
          
    }
    // cout<<a[3]<<endl;
    for(int i=1;i<n;i++){ //printing unmarked numbers(prime)

    if(a[i]==0)
    {
    cout<<i+1<<" ";
    }

    }
    cout<<"\n";


}
int main(){
    int n;
cout<<"Enter the number:";
    cin>>n;
    sieve_of_eratosthenes(n);
return 0;
}