#include<bits/stdc++.h>


using namespace std;

//Recursive approch to find length of lcs

//my approch start to end
int lcsRecursiveSE(string str1, string str2, int len1, int len2){
    if(len1>=str1.length() || len2>=str2.length()){
        return 0;
    }
    if(str1[len1]==str2[len2]){
        
        // we found comman character so we increment lenght of lcs by one
        return lcsRecursiveSE(str1,str2,len1+1,len2+1)+1;
    }

    return max(lcsRecursiveSE(str1,str2,len1+1,len2),lcsRecursiveSE(str1,str2,len1,len2+1));
}
// end to start approch
int lcsRecursive(string str1, string str2, int len1, int len2){

    if(len1==0 || len2==0){
        return 0;
    }

    if(str1[len1-1]==str2[len2-1]){
        
        // we found comman character so we increment lenght of lcs by one
        return lcsRecursive(str1,str2,len1-1,len2-1)+1;
    }

    return max(lcsRecursive(str1,str2,len1-1,len2),lcsRecursive(str1,str2,len1,len2-1));
}
//Using Memoization method
int dp[100][100];
int lcsMemoization(string str1, string str2, int len1, int len2){
    // static int idx=0;
    if(len1==0 || len2==0){
        dp[len1][len2]=0;
        return 0;
    }
    if(dp[len1][len2]!=-1){

        return dp[len1][len2];
    }
    if(str1[len1]==str2[len2]){
        return dp[len1][len2]=lcsMemoization(str1,str2,len1-1,len2-1)+1;
    }


    return dp[len1][len2]=max(lcsMemoization(str1,str2,len1-1,len2),lcsMemoization(str1,str2,len1,len2-1));
}
// using top-down apporch
int LCS(string str1,string str2){
    int len1=str1.size();
    int len2=str2.size();
    int DP[len1+1][len2+1];

    for(int i=0; i<len1+1; i++){
        for(int j=0; j<len2+1; j++){

            if(i==0 || j==0){
                DP[i][j]=0;
            }
        }
    }

    for(int i=1; i<len1+1; i++){
        for(int j=1; j<len2+1; j++){

            if(str1[i-1]==str2[j-1]){
                DP[i][j]=DP[i-1][j-1]+1;
            }
            else{
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }

    return DP[len1][len2];
}
int main(){

    string str1,str2;
    cin>>str1>>str2;

    cout<<"Recursive method:"<<lcsRecursive(str1,str2,str1.length(),str2.length())<<endl;
    
    int len=min(str1.length(),str2.length());
    for(int i=0; i<str1.length()+1; i++){
        for(int j=0; j<str2.length()+1; j++){
            dp[i][j]=-1;
        }
    }
    cout<<"Memoization method:"<<lcsMemoization(str1,str2,str1.length(),str2.length())<<endl;

    cout<<"Top-down method:"<<LCS(str1,str2)<<endl;   
    return 0;
}