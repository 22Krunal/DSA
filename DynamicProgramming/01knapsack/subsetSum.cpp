#include<bits/stdc++.h>

using namespace std;

bool dp[100][100];

bool isPresent(int array[],int n,int sum){
        
       for(int i=0;i<n+1;i++){

           for(int j=0;j<sum+1;j++){

               if(i==0)
               dp[i][j]=false;

               if(j==0)
               dp[i][j]=true;
           }
       } 
       
       for(int i=1;i<n+1;i++){

           for(int j=1;j<sum+1;j++){

               if(array[i-1]<=j){

                   dp[i][j]=(dp[i-1][(j-array[i-1])]||dp[i-1][j]);
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

    if(isPresent(array,n,sum)){

        cout<<"subset is present in the array with sum "<<sum<<endl;
    }
    else{
        cout<<"subset is not present in the array with sum "<<sum<<endl;
    }
       

    return 0;
}