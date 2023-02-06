// amzon,samsung,snapdeal,accolite
// like 0,-9,1,3,-4,5 ans is 2
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int c[n];
    for(int i=0;i<n;i++)
    c[i]=-1;
    for(int i=0;i<n;i++){
    int temp;
    cin>>temp;
    if(temp>=0&&temp<n)
     c[temp]++;

    }
    for(int i=0;i<n;i++){
    if(c[i]<0){
        cout<<i<<endl;
        return 0;
    }
    // cout<<c[i]<<" ";
    }
cout<<n<<endl;
return 0;
}