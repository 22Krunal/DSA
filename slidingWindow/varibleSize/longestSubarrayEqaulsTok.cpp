// longest subarray with sum equal to k
#include<bits/stdc++.h>


using namespace std;

int longestSubarrayEqualTok(int arr[],int n,int k){
    int sum = 0;
    // int i = 0 , j = 0;
    int mx  = 0 ;
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(mp.find(sum) != mp.end()){}
        else{
            mp[sum] = i;
        }
        if(sum == k){
            mx = max(mx,i+1);
        }
        else if(sum > k){
            if(mp.find(sum-k) != mp.end()){
                mx = max(mx,i-mp[sum-k]+1);
            }
        }
        else if(sum < k ){
            if(mp.find(sum-k) != mp.end()){
                mx = max(mx,i-mp[sum-k]+1);
            }
        }
    }
    return mx;
}
int main(){
    int n = 9;
    int arr[] = {4,1,1,1,1,-5,2,3,5};
    int k = 5; // given sum(target);
    cout << longestSubarrayEqualTok(arr,n,k);
    return 0;
}