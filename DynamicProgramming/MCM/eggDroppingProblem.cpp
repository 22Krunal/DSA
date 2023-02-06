#include<bits/stdc++.h>


using namespace std;

//Using Recursion
int minAttempt(int egg, int floor){
    if(egg == 1 || floor == 0 || floor == 1){
        return floor;
    }

    int Ans = INT_MAX;

    for(int k=1; k<=floor; k++){
            //we take here max for worst case
            // max(egg do not break, egg break) + 1  
        int tempAns = 1 + max(minAttempt(egg,floor-k),minAttempt(egg-1,k-1));

        Ans = min (Ans, tempAns);
    }

    return Ans;
}
//Using Memoization

int dp[100][100];
int minTrials(int egg, int floor){
    if(egg == 1 || floor == 0 || floor == 1){
        return floor;
    }

    if(dp[egg][floor] != -1){
        return dp[egg][floor];
    }
    
    int Ans = INT_MAX;
    for(int k=1; k<=floor; k++){
        
        // egg does not break
        if(dp[egg][floor-k] == -1){ 
            dp[egg][floor-k] = minTrials(egg,floor-k);
        }
        // egg does break
        if(dp[egg-1][k-1] == -1){
            dp[egg-1][k-1] = minTrials(egg-1,k-1);
        }

        int tempAns = 1 + max(dp[egg][floor-k],dp[egg-1][k-1]);

        Ans = min(tempAns, Ans);
    }
   
   return dp[egg][floor] = Ans;

}

int main(){

    int egg,floor; cin >> egg >> floor;

    for(int i=0; i<egg+1; i++){
        for(int j=0; j<floor+1; j++){
            dp[i][j] = -1;
        }
    } 
    cout<<minTrials(egg,floor);
    return 0;
}