#include<bits/stdc++.h>


using namespace std;

int dp[100][100];

int countofSubset(int array[],int n,int sum){

    for(int i=0; i<n+1; i++){

        for(int j=0; j<sum+1; j++){

            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=1;
            }

        }
    }

    for(int i=1; i<n+1; i++){

        for(int j=1; j<sum+1; j++){

            if(array[i-1]<=j){

                dp[i][j]=dp[i-1][j]+dp[i-1][(j-array[i-1])];
            }
            else{
                
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}
int countofCombination(int array[],int n,int sum, int target){
    
    int findSum=(sum+target)/2;
    return countofSubset(array,n,findSum);

}

int main(){


    int n;cin>>n;

    int array[n],sum=0;
    for(int i=0; i<n; i++){

        cin>>array[i];
        sum+=array[i];
    }
    
    int target;cin>>target;

    cout<<countofCombination(array,n,sum,target);
    return 0;
}