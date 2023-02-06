// ugly numbers - who have only 2,3 or 5 as there prime factors 
#include<bits/stdc++.h>


using namespace std;

int dp[100];
int nthUglyNumber(int n){
    
    // actully the counter is power of that number in n
    int c2 = 0, c3 = 0 , c5 =0;  // counters for 2,3 and 5
    dp[0] = 1; 

    for(int i=1; i<=n; i++){
        dp[i]= min({2*dp[c2],3*dp[c3],5*dp[c5]});

        if(dp[i] == 2*dp[c2]){
            c2 ++;
        }
        if(dp[i] == 3*dp[c3]){
            c3 ++;
        }
        if(dp[i] == 5*dp[c5]){
            c5 ++;
        }
    }
    return dp[n-1];
}
int main(){

    int n;cin >> n;

    cout<<nthUglyNumber(n);
    return 0;
}