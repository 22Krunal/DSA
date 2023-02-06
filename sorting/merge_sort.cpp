#include<bits/stdc++.h>


using namespace std;

void merge(int arr[],int start,int mid,int end){
    int n1 = mid-start+1;
    int n2 = end - mid;
    
    // temp arrays 
    int *a = (int*)malloc(sizeof(int)*n1);
    int *b = (int*)malloc(sizeof(int)*n2);

    for(int i=0; i<n1; i++){
        a[i] = arr[start+i];
    }
    for(int i=0; i<n2; i++){
        b[i] = arr[mid+1+i];
    }
    
    // arrraging in sorted order
    int i=0;
    int j=0;
    int k=start;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            i++;
            k++;
        }
        else{
            arr[k] = b[j];
            j++;
            k++;
        }
    }
   
   //if some elements are left
    while(i<n1){
        arr[k] = a[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = b[j];
        j++;
        k++;
    }
    free(a);
    free(b);
}
//easy way to merge
void Merge(int arr[],int start,int mid,int end){
    int i = start, k = start, j = mid+1;
    int *temp = new int[100];
    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= end){
        temp[k++] = arr[j++];
    }
    for(i=start; i<= end; i++){
        arr[i] = temp[i];
    }
    free(temp);
}
void mergeSort(int arr[], int start, int end){
    
    if(end > start){
        int mid = (start + end)/2;

        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);

        Merge(arr,start,mid,end);
    }
}
int main(){

    int arr[] = {6,3,9,5,2,19,-1,7,1};
    int n = 9;
    
    mergeSort(arr,0,n-1);
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}