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
void PrintLevelOrder(struct node *root)
{
    if (!root)
        return;
    queue<node *> Q;
    Q.push(root);
    Q.push(NULL);
    while (!Q.empty())
    {
        node *node = Q.front();
        Q.pop();
        if (node != NULL)
        {
            cout << node->data << endl;
            if (node->left)
                Q.push(node->left);
            if (node->right)
                Q.push(node->right);
        }
        else if (!Q.empty()) // push null when previous level is completed
            Q.push(NULL);
    }
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
    PrintLevelOrder(root);

    return 0;
}