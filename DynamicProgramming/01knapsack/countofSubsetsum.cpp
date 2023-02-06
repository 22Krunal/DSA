#include<bits/stdc++.h>

using namespace std;

int dp[100][100];

int countofSubset(int array[],int n,int sum){
        
       for(int i=0;i<n+1;i++){

           for(int j=0;j<sum+1;j++){

               if(i==0)
               dp[i][j]=0;

               if(j==0)
               dp[i][j]=1;
           }
       } 
       
       for(int i=1;i<n+1;i++){

           for(int j=1;j<sum+1;j++){

               if(array[i-1]<=j){

                   dp[i][j]=(dp[i-1][(j-array[i-1])]+dp[i-1][j]);
               }
               else{

                   dp[i][j]=dp[i-1][j];
               }
           }
       }
    
       
       
    return dp[n][sum];
}
int main(){

    int n;cin>>n;

    int array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }

    int sum;cin>>sum;

    cout<<countofSubset(array,n,sum)<<endl;
       

    return 0;
}