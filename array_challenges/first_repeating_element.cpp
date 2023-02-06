// 5 4 2 6 2 8->ans=2;
// oracle,amazon
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;

    int a[n],max=INT_MIN;
    for(int i=0;i<n;i++){
    cin>>a[i];
    max=max>a[i]?max:a[i];

    }
    int index[max]={0};
    for(int i=0;i<n;i++){
        if(a[i]>=0){
        index[a[i]]++;
        if(index[a[i]]>1){
            cout<<a[i];
            // return 0;
            break;
        }
        }
    }
for(int i=0;i<max;i++)
cout<<index[i]<<" ";
return 0;
}