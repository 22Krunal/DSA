#include<bits/stdc++.h>


using namespace std;

const int N = 1e3;
int dp[N];

//Recursive Approch
int minNumberofSquares(int n){
    if(n == 1 || n ==0){
        return n;
    }
    
    int Ans = INT_MAX;
    for(int i = 1; i*i <= n; i++){

       int  tempAns = minNumberofSquares(n-i*i) + 1;

       Ans = min(tempAns,Ans);

    }
    return Ans;
}

//Using Memoization
int minSquares(int n){
    if(n == 1 || n == 0){
        return dp[n] = n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    
    int Ans = INT_MAX;
    for(int i=1; i*i<=n; i++){

        if(dp[n-i*i] == -1){
            dp[n-i*i] = minSquares(n-i*i);
        }
 
        int tempAns = dp[n-i*i] + 1;

        Ans = min(tempAns, Ans);
    }

    return dp[n] = Ans;
}
int main(){

    int n;cin >> n;

    cout << minNumberofSquares(n) << endl;

    memset(dp,-1,sizeof(dp)); 
    cout << minSquares(n) << endl;

    return 0;
}