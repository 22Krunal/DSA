#include<bits/stdc++.h>


using namespace std;
const int N = 1e5;
int arr[N],Tree[4*N];
void buildST(int idx, int start, int end){

    if(start  > end){
        return ;
    }
    if(start == end){
        Tree[idx] = arr[start];
        return ;
    }

    int mid = (start + end ) / 2;

    buildST((2*idx + 1), start , mid);
    buildST((2*idx + 2), mid+1, end);
    
    Tree[idx] = max(Tree[(2*idx + 1)], Tree[(2*idx + 2)]);


}

void printST(int n){
    for(int i=0; i<n; i++){
        cout << Tree[i] << " ";
    }
    cout << endl;
}

int query(int idx, int start, int end, int left, int right){
    // out of segment
    if(start > right || left > end){
        return INT_MIN;
    }

    //complete segment
    if(start >= left && right >= end){
        return Tree[idx];
    }
    // partial segment

    int mid = (start + end)/2;

    int l = query((2*idx + 1), start, mid, left, right);
    int r = query((2*idx + 2), mid+1, end, left, right);
    
    return max(l,r);
}
void update(int idx, int start, int end, int pos, int val){

    if(start > end){
        return ;
    }
    if(start == end){
        Tree[idx] = val;
        arr[pos] = val;
        return;
    }
    int mid = (start + end)/2;
    if(pos > mid){
        update((2*idx + 2), mid+1, end, pos, val);
    }
    else{
        update((2*idx + 1), start, mid, pos, val);
    }
    Tree[idx] = max(Tree[(2*idx + 1)], Tree[(2*idx + 2)]);
}
int main(){

    int n;cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    buildST(0,0,n-1);
    printST(3*n);

    update(0,0,n-1,5,44);
    printST(3*n);
    return 0;
}