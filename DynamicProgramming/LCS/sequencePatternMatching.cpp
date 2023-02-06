//can also you the properties of LCS to solve this problem
#include<bits/stdc++.h>


using namespace std;

bool dp[100][100];

bool isSubSequence(string str1, string str2){

    int len1 = str1.length();
    int len2 = str2.length();

    for(int i=0; i<len1+1; i++){
        for(int j=0; j<len2+1; j++){

            if(j == 0){
                dp[i][j] = false;
            }
            if(i == 0){
                dp[i][j] = true;
            }
        }
    }

    for(int i=1; i<len1+1; i++){
        for(int j=1; j<len2+1; j++){

            if(str1[i-1] == str2[j-1]){
                
                dp[i][j] = (dp[i-1][j-1] && true);
            }
            else{
                dp[i][j] = (dp[i-1][j] && dp[i][j-1] );
            }
        }
    }
    
    return dp[len1][len2];
}
int main(){

    string str1, str2;cin >> str1 >> str2;

    cout<<isSubSequence(str1, str2);
    return 0;
}