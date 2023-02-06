#include<bits/stdc++.h>


using namespace std;

//my approch
int fibonacci(int n){
    
    if(n == 0 || n == 1){
        return n;
    }
    int prev1 = 1;
    int prev2 = 0;
    
    int sum = 0;
    for(int i=1; i<n; i++){

        sum = prev1 + prev2;

        prev2 = prev1;
        prev1 = sum;
    }
    return sum;
}
int main(){

    int n; cin >>n;

    cout<<fibonacci(n);
    return 0;
}