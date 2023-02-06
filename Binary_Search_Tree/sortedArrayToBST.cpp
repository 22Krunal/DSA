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
Node *sortedArrayToBST(int a[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = new Node(a[mid]);
    root->left = sortedArrayToBST(a, start, mid - 1);
    root->right = sortedArrayToBST(a, mid + 1, end);
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
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    Node *root = sortedArrayToBST(a, 0, 5);
    inorder(root);
    return 0;
}