//check again 
#include<bits/stdc++.h>


using namespace std;

struct Node{
    int data;
    struct Node*left;
    struct Node*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
}
};

int maxPathsum(Node*root,int *res){
    if(!root){
        return 0;
    }

    int l = maxPathsum(root->left,res);
    int r = maxPathsum(root->right,res);
    
   
    int tempAns = root->data + max(l,r);

    int Ans = max(tempAns,root->data+l+r);
    
    *res = max(Ans,*res);
    return tempAns;
}
int main(){
     Node*root = new Node(10);
     root->left = new Node(2);
     root->right = new Node(10);
     root->left->left = new Node(20);
     root->left->right = new Node(1);
    //  root->right->left = new Node(6);
     root->right->right = new Node(-25);
     root->right->right->left = new Node(3);
     root->right->right->right = new Node(4);

     int res = INT_MIN;
     maxPathsum(root,&res);

     cout << res <<endl;
    return 0;
}