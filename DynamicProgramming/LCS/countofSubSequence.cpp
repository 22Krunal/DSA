//count how many times str1 appears in str2
// not complete yet
#include<bits/stdc++.h>


using namespace std;

int dp[100][100];

int countSubSequence(string str1, string str2){

    int len1 = str1.length();
    int len2 = str2.length();

    for(int i=0; i<len1+1; i++){
        for(int j=0; j<len2+1; j++){

            if(j == 0){
                dp[i][j] = 1;
            }
            if(i == 0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1; i<len1+1; i++){
        for(int j=1; j<len2+1; j++){

            if(str1[i-1] == str2[j-1]){

                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
            else{

                dp[i][j] = dp[i-1][j];  
            }
        }
    }

    for(int i=0; i<len1+1; i++){
        for(int j=0; j<len2+1; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[len1][len2];
}

int main(){

    string str1, str2; cin >> str1 >> str2;

    cout<<countSubSequence(str1, str2);
    return 0;
}
