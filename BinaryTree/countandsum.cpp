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
static int c=0,sum=0;
void CountandSum(struct node*root){
    if(!root)
    return ;
    c++;
    sum+=root->data;
    if(root->right)
    CountandSum(root->right);
    if(root->left)
    CountandSum(root->left);
}
int countnodes(struct node*root){
    if(!root)
    return 0;
    return countnodes(root->left)+countnodes(root->right)+1;
}
// count leaf nodes in a tree
int lcount(struct node*root){
    if(!root){
        return 0;
    }
    if(!root->left && !root->right){
        return 1;
    }
    return lcount(root->left) + lcount(root->right);
}
// count no leaf nodes 
int nlcount(struct node*root){
    if(!root){
        return 0;
    }
    if(!root->left && !root->right){
        return 0;
    }
    return nlcount(root->left) + nlcount(root->right) + 1;
}
int sumnodes(struct node*root){
    if(!root)
    return 0;
    return sumnodes(root->left)+sumnodes(root->right)+root->data;
}
int main(){
     node*root=new node(1);
     root->left=new node(2);
     root->right=new node(3);
     root->left->left=new node(4);
     root->left->right=new node(5);
     root->right->left=new node(6);
     root->right->right=new node(7);
     root->right->right->left=new node(7);
     CountandSum(root);
      cout<<c<<" "<<sum<<endl;
      cout<<countnodes(root)<<" "<<sumnodes(root)<<endl;
      cout <<"leaf nodes in tree : " << lcount(root) << endl;
      cout <<"none leaf nodes in tree : " << nlcount(root) << endl;

    return 0;
}