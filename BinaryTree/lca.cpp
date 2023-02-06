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
bool getpath(node *root, int key, vector<int> &path)
{
    if (!root)
        return false;
    path.push_back(root->data);
    if (root->data == key)
        return true;
    if (getpath(root->left, key, path) || getpath(root->right, key, path))
        return true;
    path.pop_back();
    return false;
}
// path method
int lca(node *root, int n1, int n2)
{
    vector<int> path1, path2;
    if (!root)
        return -1;
    if (!getpath(root, n1, path1) || !getpath(root, n2, path2))
        return -1;
    int pc;
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
            break;
    }
    return path1[pc - 1];
}
// recursiv method
node *LCA(node *root, int n1, int n2)
{
    if (!root)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    node *left = LCA(root->left, n1, n2);
    node *right = LCA(root->right, n1, n2);
    if (!left && !right)
        return NULL;
    if (left && right)
        return root;
    if (!right)
        return LCA(root->left, n1, n2);
    return LCA(root->right, n1, n2);
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
    root->right->right->right = new node(8);
    cout << lca(root, 4, 6) << endl;
    node *temp = LCA(root, 4, 6);
    cout << temp->data << endl;
    return 0;
}