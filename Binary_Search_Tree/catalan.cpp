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
int catalan(int n)
{
    if (n <= 1)
        return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
        res += catalan(i) * catalan(n - i - 1);

    return res;
}
vector<Node *> constructTrees(int start, int end)
{

    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftsubtree = constructTrees(start, i - 1);
        vector<Node *> rightsubtree = constructTrees(i + 1, end);

        for (int j = 0; j < leftsubtree.size(); j++)
        {
            Node *left = leftsubtree[j];
            for (int k = 0; k < rightsubtree.size(); k++)
            {
                Node *right = rightsubtree[k];
                Node *root = new Node(i);
                root->left = left;
                root->right = right;
                trees.push_back(root);
            }
        }
    }
    return trees;
}
void preorder(Node *root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    vector<Node *> trees = constructTrees(1, 5);
    for (auto it : trees)
    {
        preorder(it);
        cout << endl;
    }
    return 0;
}