#include<bits/stdc++.h>


using namespace std;

int partition(int arr[],int l,int r){
   int pivot = arr[r];
   int i = l-1;

   for(int j=l; j<r-1; j++){
    if(arr[j] < pivot){
        i++;
        swap(arr[i],arr[j]);
    }
   }
   swap(arr[i+1],arr[r]);
   return i+1;
}
void quickSort(int arr[],int l,int r){
    if(l  < r){
        int pi = partition(arr,l,r);

        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}
//another way to partition
int Partition(int arr[],int l,int r){
    int i = l , j = r;
    int pivot = arr[l];
    do{
        do{
            i++;
        }while(arr[i] <= pivot);
        
        do{
            j--;
        }while(arr[j] > pivot);

        if(i < j){
            swap(arr[i],arr[j]);
        }
    }while(i < j);
    swap(arr[l],arr[j]);
    return j;
}
void QuickSort(int arr[],int l, int r){
    if(l < r){
        int pi = Partition(arr,l,r);

        QuickSort(arr,l,pi);
        QuickSort(arr,pi+1,r);
    }
}
int main(){
    int arr[] = {6,3,9,5,2,8,7};
    int n = 7;

    QuickSort(arr,0,n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}