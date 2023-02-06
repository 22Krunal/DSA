#include<bits/stdc++.h>


using namespace std;

void countSort(int arr[],int n){
    int mx = INT_MIN;

    for(int i=0; i<n; i++){

        if(arr[i] > mx){
            mx = arr[i];
        }
    }
    // frequency array 
    int *a = (int*)malloc(sizeof(int)*(mx+1));
    //intializing frequencies
    for(int i=0; i<mx+1; i++){
        a[i] = 0;
    }
    // counting occurance
    for(int i=0; i<n; i++){
        a[arr[i]] ++;
    }
    //storing the index of last occurance in sorted array
    int sum = 0;
    for(int i=0; i<mx+1; i++){
        a[i] += sum;
        sum = a[i];
    }
    
    //temp array to store stored array
    int *temp = (int*)malloc(sizeof(int)*n);
    for(int i=n-1; i>=0; i--){
        a[arr[i]]--;
        int idx = a[arr[i]];
        temp[idx] = arr[i];
    }
    
    free(a);
    // copy in main array 
    for(int i=0; i<n; i++){
        arr[i] = temp[i];
    }
    free(temp);
}

int main(){
    
    int arr[] = {1,3,2,3,4,1,6,4,3};
    int n = 9;
    countSort(arr,n);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}