#include<bits/stdc++.h>


using namespace std;

bool dp[100][100];

bool isPresent(int array[],int sum,int n){

    for(int i=0; i<n+1; i++){

        for(int j=0; j<sum+1; j++){

            if(i==0){
                dp[i][j]=false;
            }

            if(j==0){
                dp[i][j]=true;
            }
        }
    }

    for(int i=1; i<n+1; i++){

        for(int j=1;j<sum+1;j++){

            if(array[i-1]<=j){

                dp[i][j]=(dp[i-1][j]||dp[i-1][(j-array[i-1])]);

            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }

    }
    return dp[n][sum];
}
int minDiff(int array[],int sum,int n){

      int halfsum=ceil(sum/2);
      // to count all the possible sum of subset
      isPresent(array,sum,n);
    for(int i=0; i<sum; i++){
        
        
         if(dp[n][halfsum+i]){

            return abs(sum-2*(halfsum+i));
            
        }
        // cout<<dp[n][halfsum+i]<<endl;
    }
}
int main(){

    int n;cin>>n;

    int array[n],sum=0;
    for(int i=0; i<n; i++){
        
        cin>>array[i];
        sum+=array[i];
    }
    
    cout<<"Minimum difference of subset sum "<<minDiff(array,sum,n)<<endl;
    return 0;
}