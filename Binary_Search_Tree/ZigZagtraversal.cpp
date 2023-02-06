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
// My method
void ZigZag(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    bool leftToright = true;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp)
        {
            if (leftToright)
            {
                cout << temp->data << " ";
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            else
            {
                cout << temp->data << " ";
                if (temp->right)
                    q.push(temp->right);
                if (temp->left)
                    q.push(temp->left);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            leftToright = !leftToright;
        }
    }
}
// given method
void zigzag(Node *root)
{
    if (!root)
        return;
    stack<Node *> currLevel;
    stack<Node *> nxtLevel;
    currLevel.push(root);
    bool LeftToRight = true;
    while (!currLevel.empty())
    {

        Node *temp = currLevel.top();
        currLevel.pop();
        if (temp && LeftToRight)
        {
            cout << temp->data << " ";
            if (temp->left)
                nxtLevel.push(temp->left);
            if (temp->right)
                nxtLevel.push(temp->right);
        }
        else if (temp)
        {
            cout << temp->data << " ";
            if (temp->right)
                nxtLevel.push(temp->right);
            if (temp->left)
                nxtLevel.push(temp->left);
        }
        if (currLevel.empty())
        {
            swap(currLevel, nxtLevel);
            LeftToRight = !LeftToRight;
        }
    }
}
int main()
{
    Node *root = NULL;
    root = insert(root, 9);
    // inorder(root);
    insert(root, 8);
    insert(root, 11);
    insert(root, 4);
    insert(root, 10);

    insert(root, 12);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 5);
    insert(root, 0);
    // insert(root, 10);


    // inorder(root);
    // cout << endl;
    ZigZag(root);
    cout << endl;
    // zigzag(root);
    return 0;
}