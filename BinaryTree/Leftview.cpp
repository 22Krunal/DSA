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
void Leftview(struct node*root){
    if(!root)
    return ;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            node*node=q.front();
            q.pop();
            if(i==n-1){
                cout<<node->data<<endl;
            }
            if(node->right)
            q.push(node->right);
            if(node->left)
            q.push(node->left);
        }

    }
}

int main(){
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     root->right->left=new node(6);
     root->right->right=new node(7);
     root->right->right->right=new node(8);
     Leftview(root);
   
    return 0;
}