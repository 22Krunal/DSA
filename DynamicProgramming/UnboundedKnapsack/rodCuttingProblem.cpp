#include<bits/stdc++.h>


using namespace std;

int dp[100][100];
int maxProfit( int len[], int price[], int w, int n){

    for(int i=0; i<n+1; i++){
        for(int j=0; j<w+1; j++){

            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=0; j<w+1; j++){

            if(len[i-1]<=j){

                dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i][(j-len[i-1])]);
            }
            else{

                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][w];
}

int main(){

    int n;cin>>n;
    
    int len[n];
    for(int i=0; i<n; i++){
        cin>>len[i];
    }

    int price[n];
    for(int i=0; i<n; i++){
        cin>>price[i];
    }

    int w;cin>>w;

    cout<<maxProfit(len,price,w,n);
    return 0;
}