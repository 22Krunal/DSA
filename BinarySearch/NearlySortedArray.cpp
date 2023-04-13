#include<bits/stdc++.h>

using namespace std;

int findElement(int arr[], int n, int target){
    int l = 0 , r = n-1;

    while(l <= r){
        int mid = l + (r - l) / 2;

        if(arr[mid] == target){
            return mid;
        }
        else if(mid-1 >= 0 &&arr[mid-1] == target){
            return mid-1;
        }
        else if(mid+1 <n && arr[mid+1] == target){
            return mid+1;
        }
        else if(arr[mid] > target){
            r = mid-2;
        }
        else{
            l = mid+2;
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

    cout << findElement(arr,n,target) << endl;
    return 0;
}