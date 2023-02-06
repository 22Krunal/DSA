#include<bits/stdc++.h>


using namespace std;


int dp[100][100];
int maxScore(int arr[], int i, int j){
    if(i > j){
        return 0;
    }
    if(i == j){
        return arr[i];
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    // if i take from front 
    // l represents what is the minimum score oponent can make for me 
    int l = arr[i] + min(maxScore(arr,i-2,j), maxScore(arr,i+1,j-1));

    // if i take from end 
    // r represents what is the minimum score oponent can make for me
    int r = arr[j] + min(maxScore(arr,i,j-2), maxScore(arr,i+1,j-1));
    
    // i want to win so i take maximum of it 
    return dp[i][j] = max(l, r);   
}
int main(){

    int n;cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    memset(dp, -1, sizeof(dp));
    cout<<maxScore(arr,0,n-1);
    return 0;
}