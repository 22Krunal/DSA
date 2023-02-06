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
Node* insert(Node*root,int data){
     if(!root){
         return new Node(data);
     }
     if(root->data<data){
        root->right=  insert(root->right,data);
     }
    else if(root->data>data)
     {
         root->left= insert(root->left,data);
     }
     return root;
}
void inorder(Node*root){
    if(!root)return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node*root=NULL;
    root=insert(root,5);
    inorder(root);
    insert(root,1);
    insert(root,3);
    insert(root,6);
    insert(root,4);
    insert(root,8);
    insert(root,7);
    insert(root,2);
     inorder(root);
    return 0;
}