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
bool isIdentical(Node*root1,Node*root2){
    if(!root1&&!root2)return true;
    if(root1&&root2){
        if(root1->data==root2->data){
        bool left=isIdentical(root1->left,root2->left);
        bool right=isIdentical(root2->right,root2->right);
        return left&&right;
        }
        return false;
    }
    return false;
}
int main(){
    Node*root=NULL;
    root=insert(root,5);
    insert(root,1);
    insert(root,3);
    insert(root,6);
    insert(root,4);
    insert(root,8);
    insert(root,7);
    insert(root,2);
     inorder(root);
     Node*root1=NULL;
    root1=insert(root1,5);
    insert(root1,1);
    insert(root1,3);
    insert(root1,6);
    insert(root1,4);
    insert(root1,8);
    insert(root1,7);
    insert(root1,2);
     inorder(root1);
     cout<<endl;
     if(isIdentical(root->left,root1->left))
     cout<<"They are identical"<<endl;
     else
     cout<<"They are not identical"<<endl;
    return 0;
}