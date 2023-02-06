// Print shortest comman supersequence 

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

                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[len1][len2];

}
string printSCS(string str1, string str2){

    int comman = LCS(str1, str2);
    
    int i = str1.length();
    int j = str2.length();
    cout << "Length of SCS : " << i+j-comman <<" ";

    string ans="";


    // same character push ones and push all distict

    while(i > 0 && j > 0){

        if(dp[i][j] > max(dp[i-1][j],dp[i][j-1])){  //same character

            ans.push_back(str1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            ans.push_back(str1[i-1]);
            i--;
        }
        else{
            ans.push_back(str2[j-1]);
            j--;
        }
    }
   
   // to append remaining characters
    while(i > 0){
        ans.push_back(str1[i-1]);
        i--;
    }
    while(j > 0){
        ans.push_back(str2[j-1]);
        j--;
    }
    reverse(ans.begin(),ans.end());

    return ans;   
}

int main(){

    string str1,str2;
    cin >> str1 >> str2;

    cout<<" SCS : " << printSCS(str1,str2) << endl;
    return 0;
}