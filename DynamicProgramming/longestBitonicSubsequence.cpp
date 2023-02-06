//bitonic subsequence - first strictly increasing than strictly decresing or entriely increasing or entriely decresing 
#include<bits/stdc++.h>


using namespace std;

int LBS(int arr[], int n){

    
   vector < int > Idp(n+1, 1),Ddp(n+1,1);
    
    // longest increasing subsequence 
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            
            if(arr[i] > arr[j]){
                Idp[i] = max(Idp[i], 1 + Idp[j]);
            }
            
        }
    }
    
    // longest increasing subsequence from end (decreasing)
    for(int i =n-1; i>=0; i--){
        for(int j=n; j>i; j--){
            
            if(arr[i] > arr[j]){
                Ddp[i] = max(Ddp[i], 1 + Ddp[j]);
            }
            
        }
    }

    int Ans = INT_MIN;     
    for(int i=0; i<n; i++){
        // lis + lds - 1 (1 represents current element ocurrs in both subsequence)
        Ans = max(Ans, Idp[i] + Ddp[i] - 1);
    }

    return Ans;
}
int main(){

    int n; cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << LBS(arr, n) << endl;
    return 0;
}