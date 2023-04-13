#include<bits/stdc++.h>

using namespace std;

void LOE(vector<int>&arr,int n, int target,int start,int end,int* mx){
    if(start >= end){
        if(arr[start] == target){
            *mx = max(*mx,start);
        }
        return ;
    }
    int mid = start + (end-start)/2;
    if(arr[mid] == target){
        *mx = max(*mx,mid);
        LOE(arr,n,target,mid+1,end,mx);
    }
    if(arr[mid] > target){
        LOE(arr,n,target,start,mid-1,mx);
    }
    LOE(arr,n,target,mid+1,end,mx);
}
void FOE(vector<int>&arr,int n, int target,int start,int end,int* mn){
    if(start >= end){
        if(arr[start] == target){
            *mn = min(*mn,start);
        }
        return ;
    }
    int mid = start + (end-start)/2;
    if(arr[mid] == target){
        *mn = min(*mn,mid);
        FOE(arr,n,target,start,mid-1,mn);
    }
    if(arr[mid] > target){
        FOE(arr,n,target,start,mid-1,mn);
    }
    FOE(arr,n,target,mid+1,end,mn);
}
void FirstAndLastOcc(vector<int>&arr,int n,int target,int start, int end,int* mn,int* mx){
    // int start = 0 , end = n-1;
    int mid = start + (end-start)/2;
    if(start >= end){
        if(arr[start] == target){
            *mn = min(*mn,start);
            *mx = max(*mx,start);
        }
        return ;
    }
    
    if(arr[mid] == target){
        *mn = min(*mn,mid);
        *mx = max(*mx,mid);
        FirstAndLastOcc(arr,n,target,start,mid-1,mn,mx);
        FirstAndLastOcc(arr,n,target,mid+1,end,mn,mx);
    }
    if(arr[mid] > target){
        FirstAndLastOcc(arr,n,target,start,mid-1,mn,mx);
    }

    FirstAndLastOcc(arr,n,target,mid+1,end,mn,mx);
}
vector<int> searchRange(vector<int>& nums, int target) {
         int mn = INT_MAX,mx = INT_MIN;
         int n = nums.size();
    vector<int> res;
         if(n <= 0){
             res.push_back(-1);
        res.push_back(-1);
             return res;
         }
    FOE(nums,n,target,0,n-1,&mn);
    LOE(nums,n,target,0,n-1,&mx);

    if(mn == INT_MAX){
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }
    res.push_back(mn);
    res.push_back(mx);
    // cout << mn << mx << endl;
    return res;
} 
int main(){
    int n,target; cin >> n >> target;
    vector<int> nums(n);
    
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        nums[i] = temp;
    }
    vector<int> res = searchRange(nums,target);
    if(res[0] == -1){
        cout << 0 ;
        return 0;
    }
    cout << (res[1]-res[0]+1) << endl;
    return 0;
}