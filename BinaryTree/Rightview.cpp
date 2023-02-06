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
void Rightview(struct node*root){
    if(!root)
    return ;
    queue<node*>Q;
    Q.push(root);
    while(!Q.empty()){
          int n=Q.size();
          for(int i=0;i<n;i++){
              node*node=Q.front();
              Q.pop();
              if(i==n-1)
              cout<<node->data<<endl;
              if(node->left){
                  Q.push(node->left);
              }
              if(node->right){
                  Q.push(node->right);
              }
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
     Rightview(root);
   
    return 0;
}