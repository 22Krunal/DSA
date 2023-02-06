// we are allowed to change k elements find lcs
#include<bits/stdc++.h>


using namespace std;

int korderedLCS(int a[], int b[], int n, int m, int k){

    int dp[n+1][m+1];

    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){

            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

                if((dp[i-1][j-1] + 1) > dp[i][j] && k){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    k--;
                }
            }
        }
    }

    return dp[n][m];
}
int main(){

    int n,m,k; cin >> n >> m >> k;

    int a[n],b[m];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    cout<<korderedLCS(a, b, n, m, k);
    return 0;
}