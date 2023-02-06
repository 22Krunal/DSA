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
struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};
Info LargestBSTInBT(Node *root)
{
    if (!root)
        return {0, INT_MIN, INT_MAX, 0, true};
    if (!root->left && !root->right)
        return {1, root->data, root->data, 1, true};

    Info left = LargestBSTInBT(root->left);
    Info right = LargestBSTInBT(root->right);

    Info curr;
    curr.size = left.size + right.size + 1;
    if (left.isBST && right.isBST && left.max < root->data && right.min > root->data)
    {
        curr.isBST = true;
        curr.max = max(root->data, max(left.max, right.max));
        curr.min = min(root->data, min(left.min, right.min));
        curr.ans = curr.size;
        return curr;
    }
    curr.ans = max(left.ans, right.ans);
    curr.isBST = false;
    return curr;
}
int main()
{
    Node *root = new Node(15);
    root->left = new Node(14);
    root->right = new Node(30);
    root->left->left = new Node(5);
    cout << LargestBSTInBT(root).ans << endl;
    return 0;
}