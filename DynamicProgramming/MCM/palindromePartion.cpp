#include<bits/stdc++.h>


using namespace std;


bool isPalindrome(string str, int i, int j){
    if(i >= j ){
        return true;
    }

    while( j > i){

        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }

    return true;
}
//Recursive method
int minPartion(string str, int i, int j){

    if(isPalindrome(str, i, j)){
        return 0;
    }
    
    int Ans = INT_MAX;
    for(int k=i; k<=j-1; k++){

        int tempAns = 1 + minPartion(str,i,k) + minPartion(str,k+1,j);

        Ans = min(Ans,tempAns);
    }

    return Ans;
}
//Using Memoization
int dp[100][100];
int MinPartion(string str, int i, int j){

    if(isPalindrome(str,i,j)){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int Ans = INT_MAX; 
    for(int k=i; k<=j-1; k++){

        int tempAns = 1 + MinPartion(str,i,k) + MinPartion(str,k+1,j);

        Ans = min(Ans,tempAns);
    }

    return dp[i][j] = Ans;
}

// More Optimized version specially for leetcode

int minpartion(string str, int i, int j){
    if(isPalindrome(str,i,j)){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int Ans = INT_MAX;
    for(int k=i; k<=j-1; k++){

        if(dp[i][k] == -1){
            dp[i][k] = minpartion(str,i,k);
        }
        if(dp[k+1][j] == -1){
            dp[k+1][j] = minpartion(str,k+1,j);
        }

        int tempAns = 1 + dp[i][k] + dp[k+1][j]; 

        Ans = min(Ans, tempAns);

    }

    return dp[i][j] = Ans;
}
int main(){
    
    string str; cin >> str;

    cout <<"Recursive Method : " << minPartion(str,0,str.length()-1) << endl;

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            dp[i][j] = -1;
        }
    }
    cout <<"Using Memoization : " << minpartion(str,0,str.length()-1) << endl;

    return 0;
}