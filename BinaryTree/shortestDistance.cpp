#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    };
};
// find lowest comman ancestor
node *lca(node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    node *left = lca(root->left, n1, n2);
    node *right = lca(root->right, n1, n2);
    if (!left && !right)
        return NULL;
    if (left && right)
        return root;
    if (!left)
        return lca(right, n1, n2);
    return lca(left, n1, n2);
}
// find distance from root node to given node
int findDis(struct node *root, int k, int dis)
{
    if (!root)
        return -1;
    if (root->data == k)
        return dis;
    int left = findDis(root->left, k, dis + 1);
    if (left != -1)
        return left;
    return findDis(root->right, k, dis + 1);
}
// find shorest distance between two nodes n1,n2
int shortestDistance(struct node *root, int n1, int n2)
{
    node *node = lca(root, n1, n2);
    int d1 = findDis(node, n1, 0);
    int d2 = findDis(node, n2, 0);
    return d1 + d2;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout << shortestDistance(root, 4, 7) << endl;
    return 0;
}
/*
    1
   / \
  2    3
 / \  / \
4   5 6  7
*/