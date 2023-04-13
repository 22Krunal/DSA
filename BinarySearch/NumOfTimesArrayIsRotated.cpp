#include<bits/stdc++.h>


using namespace std;

//May not work for some cases
int NumOfRotations(int arr[],int n,int start ,int end){
    if(start >= end){
        return 0;
    }
    int mid = start + (end-start)/2;
    if(arr[mid] > arr[mid+1]){
        return n-mid;
    }
    if(arr[mid] < arr[mid-1]){
        return mid;
    }
    return max(NumOfRotations(arr,n,start,mid-1) , NumOfRotations(arr,n,mid+1,end));
}

//Appropriate verison 
int NOR(int arr[],int n, int start,int end){
    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid] < arr[(mid+n-1)%n] && arr[mid] < arr[(mid+1)%n]){   
            return mid;
        }
        else if(arr[mid] > arr[end]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return 0;
}
int main(){

    int n; cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout<<NumOfRotations(arr,n,0,n-1) << endl;
    cout << NOR(arr,n,0,n-1) << endl;
    return 0;
}