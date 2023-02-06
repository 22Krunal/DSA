// lps - longest palindromic substring
#include<bits/stdc++.h>


using namespace std;


int dp[100][100];
int LPS(string str1, string str2){
    int n = str1.length();

    for(int i=0; i<n+1; i++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    
    int maxAns = INT_MIN;
    for(int i=1; i<n+1; i++){
        for(int j=1; j<n+1; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxAns = max(dp[i][j],maxAns);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return maxAns;
}
int main(){
    string str; cin >> str;
    
    memset(dp,-1,sizeof(dp));

    string rstr = str;
    reverse(rstr.begin(), rstr.end());
    cout<<LPS(str, rstr);
    return 0;
}