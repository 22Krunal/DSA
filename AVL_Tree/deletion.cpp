#include<bits/stdc++.h>


using namespace std;

struct Node{
    int data;
    int height;
    struct Node*left;
    struct Node*right;
    Node(int val){
        data = val;
        height = 1;
        left = NULL;
        right = NULL;
    }
};
struct Node*root = NULL;
Node*insert(Node*root,int val){
    if(!root){
        return new Node(val);
    }
    if(root->data > val){
        root->left = insert(root->left,val);
    }
    else if(root->data < val){
        root->right = insert(root->right,val);
    }
    root 
}
int main(){

    cout<<"";
    return 0;
}