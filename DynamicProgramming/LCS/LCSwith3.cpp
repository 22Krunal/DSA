#include<bits/stdc++.h>


using namespace std;


int dp[100][100][100];
int LCS(string str1, string str2, string str3, int i, int j, int k){

    if(i == 0  || k==0 || j == 0){
        return 0;
    }

    if(dp[i][j][j] != -1){
        return dp[i][j][k];
    } 
    if(str1[i-1] == str2[j-1] && str2[j-1] == str3[k-1]){
        return dp[i][j][k] = 1 + LCS(str1,str2,str3,i-1,j-1,k-1);
    }

    int l = LCS(str1,str2,str3,i-1,j,k);
    int m = LCS(str1,str2,str3,i,j-1,k);
    int r = LCS(str1,str2,str3,i,j,k-1);

    return dp[i][j][k] = max(max(l,m),r);


}
int main(){

    string str1, str2, str3 ; cin >> str1 >> str2 >> str3;
    
    memset(dp,-1,sizeof(dp));

    cout << LCS(str1,str2,str3,str1.length(),str2.length(),str3.length());
    return 0;
}