#include<bits/stdc++.h>


using namespace std;


int INFI = 1e9;
// int dp[100];



int minJumps(int arr[], int n){
  
    vector < int > dp(n, INFI);

     dp[0] = 0;  
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){

            if(i <= j + arr[j]){
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
    }
    
    return dp[n-1];
}
int main(){

    int n; cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
 
    cout << minJumps(arr, n) << endl;
    return 0;
}