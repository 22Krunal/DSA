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
    
    // to handle negative pathsum
    // and also because we can take pathsum from none leaf node also
    int tempAns = max(root->data,root->data + max(l,r));

    int Ans = max(tempAns,root->data+l+r);
    
    *res = max(Ans,*res);
    return tempAns;
}
int main(){
     Node*root = new Node(1);
     root->left = new Node(2);
     root->right = new Node(3);
     root->left->left = new Node(4);
     root->left->right = new Node(5);
     root->right->left = new Node(6);
     root->right->right = new Node(7);
     
     int res = INT_MIN;
     maxPathsum(root,&res);

     cout << res <<endl;
    return 0;
}