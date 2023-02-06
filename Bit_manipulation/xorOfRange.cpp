#include<bits/stdc++.h>

using namespace std;
int XorTillN(int n){
    if(n%4 == 0){
        return n;
    }
    if(n%4 == 1){
        return 1;
    }
    if(n%4 == 2){
        return n+1;
    }
    return 0;
}
int XorOfRange(int L,int R){
    return XorTillN(L-1) xor XorTillN(R);
}
int main(){
    int L,R; cin >> L >> R;
    cout << XorOfRange(L,R) << endl;
    return 0;
}