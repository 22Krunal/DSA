#include<bits/stdc++.h>


using namespace std;

bool dp[100][100];

bool subsetSum(int array[],int sum,int n){

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

                dp[i][j]=(dp[i-1][(j-array[i-1])]||dp[i-1][j]);

            }
            else{

                dp[i][j]=dp[i-1][j];
            }
        }
    }

    
    return dp[n][sum];
}

bool isPartition(int array[],int sum,int n){
   
   // we find if (sum/2) sum we can achive or not and rest of subset have same sum;
    return subsetSum(array,sum/2,n); 

}
int main(){

    int n;cin>>n;
    
    int array[n],sum=0;
    for(int i=0; i<n; i++){

        cin>>array[i];
        sum+=array[i];
    }

    //if sum of element is even than only we can make partition 
    if(sum%2==0 && isPartition(array,sum,n)){

        cout<<"Yes we can make equal sum partition "<<endl;
    }
    else{
        cout<<"NO,we can't make equal sum partition"<<endl;
    }
    return 0;
}
