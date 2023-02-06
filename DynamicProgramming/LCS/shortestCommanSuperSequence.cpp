#include<bits/stdc++.h>


using namespace std;


int dp[100][100];
int LCS(string str1, string str2){

    int len1 = str1.length();
    int len2 = str2.length();

    for(int i=0; i<len1+1; i++){
        for(int j=0; j<len2+1; j++){
            
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    for(int i=1; i<len1+1; i++){
        for(int j=1; j<len2+1; j++){

            if(str1[i-1] == str2[j-1]){

                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{

                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }


        }
    }

    return dp[len1][len2];
}
int shortestCommanSuperSqeuence(string str1, string str2){
    int comman=LCS(str1,str2);

    // geek+eke - ek = geeke
    return str1.length()+str2.length()-comman;
}
int main(){

    string str1,str2;
    cin>> str1 >> str2;

    cout<<shortestCommanSuperSqeuence(str1,str2);
    return 0;
}