#include<bits/stdc++.h>

using namespace std;

// N=1  ans = 1
// N=2  ans = 3
// N=3  ans = 0
// N=4  ans = 4
// N=5  ans = 1
// N=6  ans = 7
// N=7  ans = 0
// N=8  ans = 8
// ....

// from observations  

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
int Xor(int n){
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = ans xor i;
    }
    return ans;
}
int main(){
    int n; cin >> n;
    cout << Xor(n) << " " << XorTillN(n) << endl;
    return 0;
}
