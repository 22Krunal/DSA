#include<bits/stdc++.h>


using namespace std;

int dp[100][100];
int LCS(string str1, string str2){

    int len1 = str1.length();
    int len2 = str2.length();

    for(int i=0; i<len1+1; i++){
        for(int j=0; j<len2+1; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1; i<len1+1; i++){
        for(int j=1; j<len2+1; j++){

            if(str1[i-1] == str2[j-1]){

                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{

                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

        }
    }

    return dp[len1][len2];
}

int minInsertion(string str){
    
    string rstr = str;
    reverse(rstr.begin(), rstr.end());
    int comman = LCS(str,rstr);
    
    return str.length() - comman;
}
int main(){

    string str; cin >> str; 

    cout<<minInsertion(str);
    return 0;
}