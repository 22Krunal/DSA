// x : heap y: pea
// min number of insertion and deletion to make x--->y
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

                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{

                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[len1][len2];
}

int minInsertion( string str1, string str2){

    return str2.length()-LCS(str1, str2);
}
int minDeletion(string str1, string str2){

    return str1.length()-LCS(str1, str2);
}
int main(){
    
    string str1,str2;
    cin>>str1>>str2;
    
    cout <<"Minimum Number of Insertion :" << minInsertion(str1, str2) <<endl;
    cout <<"Minimum Number of Deletion :"<< minDeletion(str1, str2) <<endl;
    return 0;
}