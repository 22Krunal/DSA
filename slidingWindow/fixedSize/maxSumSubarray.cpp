#include<bits/stdc++.h>


using namespace std;


int maxSumSubarray(int arr[], int n, int k){
    int sum = 0;

    for(int i=0; i<k; i++){ 
        sum += arr[i];
    }

    int mx = INT_MIN;
    int i = 0 , j = k;

    while(j < n){
        mx = max(mx,sum);
        sum -= arr[i];
        sum += arr[j];
        i++;
        j++;
    }
    return mx;
}

int main(){
    int n = 8;
    int arr[] = {1,5,6,34,62,7,8,21};
    int k = 3;
    
    cout << maxSumSubarray(arr,n,k) << endl;
    return 0;
}