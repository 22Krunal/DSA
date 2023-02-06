#include<bits/stdc++.h>


using namespace std;

int dp[100];
int waysToPair(int n){

    if(n == 1 || n == 0 || n == 2){
        return n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    if(dp[n-1] == -1){
        dp[n-1] = waysToPair(n-1);
    }
    if(dp[n-2] == -1){
        dp[n-2] = waysToPair(n-2);
    }
    
    // for nth person = remain single + begin paired
    return dp[n] = (dp[n-1] + (n-1) * dp[n-2]);
    
}
int main(){

    int n; cin >> n;
    
    memset(dp,-1,sizeof(dp));
    cout << waysToPair(n) << endl;
    return 0;
}