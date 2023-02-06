#include<bits/stdc++.h>


using namespace std;


// Recursive Method 
int MCM(int arr[], int i, int j){

    if(i >= j){
        return 0;
    }

    int Ans = INT_MAX;

    for(int k= i; k <= j-1; k++){

        // cost of matix's maluliplication + cost of resultant matrix's multiplication
        int tempAns = MCM(arr,i,k)+ MCM(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        
        Ans = min(tempAns, Ans);
    }

    return Ans;
}
//Using Memoization 
int dp[100][100];
int mcm(int arr[], int i, int j){
    if(i >= j){
        return 0;
    }
    if( dp[i][j] != -1){
        return dp[i][j];
    }
    int Ans = INT_MAX;
    for(int k=i; k<=j-1; k++){

        int tempAns = MCM(arr,i,k) + MCM(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
    }

    return dp[i][j] = Ans;
}
int main(){

    int n ; cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout <<"Recursive Method : "<< MCM(arr,1,n-1) << endl;
    cout <<"Using Memoization : "<< MCM(arr,1,n-1) << endl;
     
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){

            dp[i][j] = -1;
        }
    }
    
    return 0;
}