#include<bits/stdc++.h>

using namespace std;
struct node{
    int data;
    struct node*left;
    struct node*right;
    node(int value){
        data=value;
        left=NULL;
        right=NULL;
    };
};
int height(struct node*root){
    if(!root)
    return 0;
    return max(height(root->left),height(root->right))+1;
}
bool isBalanced(struct node*root){
    if(!root)
    return true;
    if(!isBalanced(root->left))
    return false;
    if(!isBalanced(root->right))
    return false;
    int lh=height(root->left);
    int rh=height(root->right);
    if(abs(lh-rh)<=1)
    return true;
    else 
    return false; 
}
int main(){
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
    //  root->right->left=new node(6);
    //  root->right->right=new node(7);
     root->left->left->right=new node(8);
    //  root->left->left->left=new node(9);
     cout<<isBalanced(root)<<endl;
   
    return 0;
}