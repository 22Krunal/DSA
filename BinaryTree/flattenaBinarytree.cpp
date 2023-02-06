#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    };
};
void flatten(node*root){
    if(!root||!root->left&&!root->right)return ;
    if(root->left){
        flatten(root->left);
        node*temp=root->right;
        root->right=root->left;
        root->left=NULL;
        node*tail=root->right;
        while(tail->right)tail=tail->right;
        tail->right=temp;
    }
    flatten(root->right);
}

void inorder(node*root){
    if(!root)return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void print(node*root){
    node*temp=root;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    cout<<endl;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    inorder(root);
    cout<<endl;
    flatten(root);
    inorder(root);
    cout<<endl;
    print(root);
    return 0;
}
/*
    1
   / \
  2    3
 / \  / \
4   5 6  7
*/