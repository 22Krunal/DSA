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
int sumReplace(struct node*root){
    if(!root)return 0;
 return root->data=root->data+sumReplace(root->left)+sumReplace(root->right);

}
void Preorder(struct node*root){
    if(!root)return ;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
int main(){
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     root->right->left=new node(6);
     root->right->right=new node(7);
    sumReplace(root);
    Preorder(root); 
    return 0;
}