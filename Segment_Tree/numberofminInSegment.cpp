#include<bits/stdc++.h>


using namespace std;

const int N = 1e5+2;
int arr[N];
pair<int,int> Tree[4*N];

void buildST(int idx, int start , int end){

    
    if(start > end ){
        return ;
    }
    if(start == end){
        Tree[idx].first = arr[start];
        Tree[idx].second = 1;
        return ;
    }

    int mid = (start + end)/2;

    buildST((2*idx + 1), start, mid);  // left subtree
    buildST((2*idx + 2), mid+1, end);  // right subtree

    if(Tree[(2*idx + 1)].first > Tree[(2*idx + 2)].first){
        Tree[idx].first = Tree[(2*idx + 2)].first;
        Tree[idx].second = Tree[(2*idx + 2)].second;
    }
    else if(Tree[(2*idx + 1)].first < Tree[(2*idx + 2)].first){
        Tree[idx].first = Tree[(2*idx + 1)].first;
        Tree[idx].second = Tree[(2*idx + 1)].second;
    }
    else{
        Tree[idx].first = Tree[(2*idx + 2)].first;
        Tree[idx].second = Tree[(2*idx + 2)].second + Tree[(2*idx + 1)].second;
    }
}


pair<int,int> query(int idx, int start, int end, int left, int right){

    if(start > end || (left > end  || right < start)){
        return {INT_MAX,-1};
    }
    
    //complete segment
    if(left <= start && right >= end){
        return Tree[idx]; 
    }

    // partial segment
    int mid = (start + end)/2;
    
    pair<int,int> l = query((2*idx + 1), start, mid, left, right);
    pair<int,int> r = query((2*idx + 2), mid+1, end, left, right);
    
    pair<int,int> ans;

    if(l.first == r.first){
        ans.first = l.first;
        ans.second = l.second + r.second;
        return ans;
    }
    return l.first > r.first ? r : l;
}
int main(){

    int n;cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];

    }
    buildST(0,0,n-1);
    pair < int , int > ans;
   ans = query(0,0,n-1, 1,5);
   cout << ans.first << " " << ans.second << endl;
    return 0;
}