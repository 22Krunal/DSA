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
    }
};
int search(int a[],int data,int start,int end){
    for(int i=start;i<end;i++)
    if(a[i]==data)
    return i;
}
node* buildTree(int preorder[],int inorder[],int start,int end){
       static int index=0;
       if(start>end)return NULL;
       int curr=preorder[index];
       index++;

        node*root=new node(curr);
       if(start==end) return root;
       int pos=search(inorder,curr,start,end);
       root->left=buildTree(preorder,inorder,start,pos-1);
       root->right=buildTree(preorder,inorder,pos+1,end);
       

}
void inorder(struct node*root){
    if(!root)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
  int preorder[]={1,2,4,5,3,6};
  int Inorder[]={4,2,5,1,6,3};
 struct node*root=buildTree(preorder,Inorder,0,5);
 inorder(root);
    return 0;
}