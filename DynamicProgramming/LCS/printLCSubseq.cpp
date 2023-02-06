#include<bits/stdc++.h>


using namespace std;

int dp[100][100];

int LCS(string str1, string str2){
    
    int len1=str1.size();
    int len2=str2.size();

    for(int i=0; i<len1+1; i++){
        for(int j=0; j<len2+1; j++){

            if(i==0 || j==0){
                dp[i][j]=0;
            }

        }
    }

    for(int i=1; i<len1+1; i++){
        for(int j=1; j<len2+1; j++){

            if(str1[i-1]==str2[j-1]){

                dp[i][j]=1+dp[i-1][j-1];
            }
            else{

                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[len1][len2];


}

string printLCS(string str1,string str2){
   
   int len=LCS(str1,str2);
   string ans="";
   int i=str1.length();
   int j=str2.length();

   
   while( i>=0 && j>=0){

           if(dp[i][j]>max(dp[i-1][j],dp[i][j-1])){
               ans+=str1[i-1];
               i--;
               j--;
           }
           else{
               dp[i-1][j]>dp[i][j-1]?i--:j--;
           }
       
   }
    reverse(ans.begin(),ans.end());

    return ans;
}
int main(){

    string str1,str2;
    cin>>str1>>str2;

    cout<<printLCS(str1,str2);
    return 0;
}