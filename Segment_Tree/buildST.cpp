#include<bits/stdc++.h>


using namespace std;

const int N = 1e5+2;
int arr[N], Tree[4*N];

void buildST(int idx, int start , int end){

    
    if(start > end ){
        return ;
    }
    if(start == end){
        Tree[idx] = arr[start];
        return ;
    }

    int mid = (start + end)/2;

    buildST((2*idx + 1), start, mid);  // left subtree
    buildST((2*idx + 2), mid+1, end);  // right subtree

    Tree[idx] = Tree[(2*idx + 1)] + Tree[(2*idx + 2)]; // parent node  = left subtree + right subtree
}

void printST(int n){
    for(int i=0; i<n; i++){
        cout << Tree[i] << " ";
    }
    cout << endl;
}

int main(){

    int n;cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    buildST(0,0,n-1);
    printST(4*n);

    return 0;
}