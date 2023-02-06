// In this we have to print max element till every ith index 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
        int max=a[0];
    for (int i = 0; i < n; i++)
    {
        max=max>a[i]?max:a[i];
        cout<<max<<" ";
        /* code */
    }
    
cout<<endl;
return 0;
}