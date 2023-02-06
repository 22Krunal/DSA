// In This problem we have to find minimum number of coins to make sum out of it
#include<bits/stdc++.h>


using namespace std;

int INFI=INT_MAX-1;
int dp[100][100];
int minCoins( int coin[], int sum, int n){

    //intializing 1st row and column
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){

            if(j==0){
                dp[i][j]=0;
            }
            if(i==0){
                dp[i][j]=INFI;
            }
        }
    }

    //intializing 2nd row 
    // since there is only one coin so check if we can make sum or not
    for(int j=1; j<sum+1; j++){

        if(j%coin[0]==0){
            dp[1][j]=j/coin[0];
        }
        else{
            dp[1][j]=INFI;
        }
    }

    for(int i=2; i<n+1; i++){

        for(int j=1; j<sum+1; j++){

            if(coin[i-1]<=j){

                //if we take coin so add value by 1 in count else 0
                dp[i][j]=min(dp[i-1][j],1+dp[i][(j-coin[i-1])]);
            }
            else{
                
                dp[i][j]=dp[i-1][j];
            }
            // cout<< dp[i][j] <<" ";
        }
        // cout<<endl;
    }
     
     for(int i=1; i<n+1; i++){
         for(int j=1; j<sum+1; j++){
             cout << dp[i][j] << " ";
         }
         cout<<endl;
     }
    return dp[n][sum];

}

int main(){

    int n;cin>>n;

    int coin[n];
    for(int i=0; i<n; i++){
        cin>>coin[i];
    }

    int sum;cin>>sum;

    cout<<minCoins(coin,sum,n);
    return 0;
}