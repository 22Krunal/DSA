#include<bits/stdc++.h>


using namespace std;

int dp[100][100];

int LCS(string str1, string str2){

    int len1 = str1.size();
    int len2 = str2.size();

    for(int i=0; i<len1+1; i++){
        for(int j=0; j<len2+1; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    
    int maxlen=INT16_MIN;
    for(int i=1; i<len1+1; i++){
        for(int j=1; j<len2+1; j++){

            if(str1[i-1]==str2[j-1]){

                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{

                dp[i][j]=0; //discountinous charcter for substring 
            }
            maxlen=max(maxlen,dp[i][j]);
        }
    }
    
    return maxlen;
}

int main(){
    

    string str1,str2;
    cin>>str1>>str2;

    cout<<LCS(str1,str2);
    return 0;
}