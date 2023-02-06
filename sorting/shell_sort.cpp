#include<bits/stdc++.h>


using namespace std;

void shellSort(int arr[],int n){

    for(int gap = n/2; gap>=1; gap/=2){
        for(int i = gap; i<n; i++){
            int curr = arr[i];
            int j = i-gap;
            while(j >=0 && arr[j] > curr){
                arr[j+gap] = arr[j];
                j -= gap;
            }
            arr[j+gap] = curr;
        }
    }
}
int main(){
    
    int n = 5;
    int arr[]={78, 88, 35, 25, 67};

    shellSort(arr,n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout<<"";
    return 0;
}