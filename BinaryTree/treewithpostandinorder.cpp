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
 int search(int a[],int k,int start,int end){
     for(int i=start;i<end;i++)
     if(k==a[i])
     return i;
     return -1;
 }
 node*buildTree(int postorder[],int inorder[],int start,int end){
     static int index=0;
     if(start>end)
     return NULL;
     int curr=postorder[index];
     index--;
     node*root=new node(curr);
     if(start==end)
     return root;
     int pos=search(inorder,curr,start,end);
     root->right=buildTree(postorder,inorder,pos+1,end);
     root->left=buildTree(postorder,inorder,start,pos-1);
return root;
 }
 void preorder(struct node*root){
     if(!root)
     return ;
     cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);
 }
 int main(){
     int postorder[]={4,5,2,6,3,1};
     int inorder[]={4,2,5,1,6,3};
     struct node*root=buildTree(postorder,inorder,0,5);
     preorder(root);
     return 0;
 }