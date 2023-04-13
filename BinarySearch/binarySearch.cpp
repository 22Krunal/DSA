#include<bits/stdc++.h>


using namespace std;


int BinarySearch(int arr[],int n, int target ){
    int start = 0 , end = n-1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] > target){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return -1;
}
int main(){
    int n,target; cin >> n >> target;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout<<BinarySearch(arr,n,target)<<endl;
    return 0;
}