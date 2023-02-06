#include<bits/stdc++.h>

using namespace std;

//recursive approch
int maxProfit(int wt[],int val[],int w,int n){
    //base contd
    if(n==0 || w==0){
        return 0;
    }
    
    //choice diagram
    if(wt[n-1]<=w){

        return max(val[n-1]+maxProfit(wt,val,w-wt[n-1],n-1),maxProfit(wt,val,w,n-1));
    }

    return maxProfit(wt,val,w,n-1);

}

//memoization (DP)

int dp[100][100];

int MaxProfit(int wt[],int val[],int w,int n){

    if(n==0 || w==0){

        return 0;
    }
    
    if(dp[n][w] !=-1){

        return dp[n][w];
    }

    if(wt[n-1] <= w){

        dp[n][w]=max(val[n-1]+MaxProfit(wt,val,w-wt[n-1],n-1),MaxProfit(wt,val,w,n-1));
        return dp[n][w];
    }

    return dp[n][w]=MaxProfit(wt,val,w,n-1);

}
//Top-down approch
int dp2[100][100];

int maxprofit(int wt[],int val[],int w,int n){

    for(int i=0;i<n+1;i++){

        for(int j=0;j<w+1;j++){

            if(wt[i-1]<=j)
            dp2[i][j]=max(val[i-1]+dp2[i-1][(j-wt[i-1])],dp2[i-1][j]);
            else
            dp2[i][j]=dp2[i-1][j];
            cout<<dp2[i][j]<<" ";
        }
        cout<<endl;
    }
    

   
    return dp2[n][w];
}
int main(){

    int n;
    cin>>n;

    int wt[n],val[n];
    
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }

    for(int i=0;i<n;i++){
        cin>>val[i];
    }

    int w;cin>>w;

    cout<<"Maximum Profit using recursive fuction: "<<maxProfit(wt,val,w,n)<<endl;

    for(int i=0;i<=n;i++){

        for(int j=0;j<=w;j++){

            dp[i][j]=-1;
        }
    }
    cout<<"Maximum Profit using memoization fuction: "<<MaxProfit(wt,val,w,n)<<endl;
       
    cout<<"Maximum Profit using Topdown apporch: "<<maxprofit(wt,val,w,n)<<endl;

    return 0;
}

