// take lcs with same string but dont increase length of lcs if index of occurance is same
// aabebcdd -{e,c} not included becuase at same index while for a - 0,1 so cross matching is possible 
#include<bits/stdc++.h>


using namespace std;

int dp[100][100];
int LRS(string str){

    int len = str.length();

    for(int i=0; i<len+1; i++){
        for(int j=0; j<len+1; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }

    for(int i=1; i<len+1; i++){
        for(int j=1; j<len+1; j++){

            if(i!=j && str[i-1] == str[j-1]){
                
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{

                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[len][len];
}

int main(){

    string str; cin >> str;

    cout<<LRS(str);
    return 0;
}