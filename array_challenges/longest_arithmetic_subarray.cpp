// In this you have to find longest subarray with difference between two consecutice element are same
// like 1 9 7 5 3 4 here ans is 4 because 9 7 5 3 have same difference of 2
//kick start question
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int pd=a[1]-a[0],count=2,max=2;
    for(int i=1;i<n-1;i++){
        int current =a[i+1]-a[i];
        if(current ==pd){
            count++;

        }else{
            pd=current;
            max=max>count?max:count;
            count=2;
        }
    }
cout<<max;
return 0;
}