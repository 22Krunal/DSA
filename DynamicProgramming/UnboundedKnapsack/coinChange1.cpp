//In this problem we have to find count of possible ways to make sum out of coin array
#include<bits/stdc++.h>


using namespace std;

int dp[100][100];
// initiallize like first row 0 and first column except first cell 1
int numberofWays( int coin[], int sum, int n){

    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){

            if(j==0){
                dp[i][j]=1;
            }
            if(i==0 ){
                dp[i][j]=0;
            }

        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){

            if(coin[i-1]<=j){

                dp[i][j]=dp[i-1][j]+dp[i][(j-coin[i-1])];
            }
            else{
                
                dp[i][j]=dp[i-1][j];
            }
        }
    }
        for(int i=0 ; i<n+1 ;i++){
            for(int j=0; j<sum+1; j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
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

    cout<<numberofWays(coin,sum,n)<<endl;
    return 0;
}