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
Node *insert(Node *root, int data)
{
    if (!root)
    {
        return new Node(data);
    }
    if (root->data < data)
    {
        root->right = insert(root->right, data);
    }
    else if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    return root;
}
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
bool isBST(Node *root, Node *min, Node *max)
{
    if (!root)
    {
        return true;
    }
    if (min!=NULL && min->data >= root->data)
    {
        return false;
    }
    if (max!=NULL && max->data <= root->data)
    {
        return false;
    }
    bool leftvalid = isBST(root->left, min, root);
    bool rightvalid = isBST(root->right, root, max);
    return (leftvalid&&rightvalid);
}
int main()
{
    // Node *root = NULL;
    // root = insert(root, 5);
    // insert(root, 2);
    // insert(root, 11);
    // insert(root, 9);
    // insert(root, 10);
    // insert(root, 7);
    // insert(root, 8);
    // insert(root, 6);
    // inorder(root);
    //make bt
    Node*root;
    root=new Node(2);
    root->left=new Node(1);
    root->right=new Node(3);
    cout<<root->data<<endl;

    if(isBST(root,NULL,NULL))
    cout<<"This is a BST"<<endl;
    else
    cout<<"This is not a BST"<<endl;
    // inorder(root);
    return 0;
}