#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void calpointers(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    if (!root)
        return;

    calpointers(root->left, first, mid, last, prev);
    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;
    calpointers(root->right, first, mid, last, prev);
}
void RestoreBST(Node *root)
{
    if (!root)
        return;
    Node *last, *mid, *first, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;
    calpointers(root, &first, &mid, &last, &prev);
    if (first && last)
    {
        swap(&(last->data), &(first->data));
    }
    else if (mid && first)
    {
        swap(&(first->data), &(mid->data));
    }
}
Node*constructBST(int a[],int start ,int end){
    if(start>end)return NULL;
    int mid=(start+end)/2;
    Node*root=new Node(a[mid]);
    root->left=constructBST(a,start,mid-1);
    root->right=constructBST(a,mid+1,end);
return root;
}
void inorder(Node*root){
    if(!root)return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    int a[]={1,8,3,4,5,6,7,2};
    Node*root=constructBST(a,0,7);
    inorder(root);
    RestoreBST(root);
    cout<<endl<<"Restored BST:"<<endl;
    inorder(root);
    return 0;
}