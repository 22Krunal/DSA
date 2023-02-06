#include<bits/stdc++.h>


using namespace std;


int dp[100];
int LIS(int arr[], int n){

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = 1;   //single element is also a LIS

    for(int i=0; i<n; i++){
        if(arr[n] > arr[i]){
            dp[n] = max(dp[n], 1 + LIS(arr,i));
        }
    }
    
    return dp[n];
}
int main(){

    int n; cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    memset(dp,-1,sizeof(dp));
    cout<<LIS(arr, n-1) << endl;
    for(int i=0; i<n+1; i++){
        cout << dp[i]  << " ";
    }
    return 0;
}