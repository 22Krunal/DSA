// There is a theme park who want to know which day is record breaking day
// we are given N days,day is record breker if 
// 1.it has maximum numer of visitor than each previous day
// 2.either it is the last day,or the number of visitors on the day strictly larger than the following day
// it should satisfy both of the consditions (first day also can be record breaker)
// kick start
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int max=-1;
    for(int i=0;i<n;i++){
        if(a[i]>max){
            if(i!=n-1&&a[i]>a[i+1])
            {
                // cout<<a[i];
                max=a[i];
                cout<<a[i]<<" ";
            }
            else if(i==(n-1)){
                cout<<a[i];
            }
        }

    }
cout<<endl;
return 0;
}