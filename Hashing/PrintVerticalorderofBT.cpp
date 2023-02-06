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

// this both can be done in one sigle function try that
map<int, vector<int>> hd;
// to map all elements at hd distance from root
// count horizontal distance
void countHD(Node *root, int HD)
{
    if (!root)
        return;

    hd[HD].push_back(root->data);
    countHD(root->left, HD - 1);
    countHD(root->right, HD + 1);
}
void verticalorder(Node *root)
{
    if (!root)
        return;

    countHD(root, 0);

    map<int, vector<int>>::iterator it;

    for (it = hd.begin(); it != hd.end(); it++) // travers till all distance pushed in map

        for (int i = 0; i < (it->second).size(); i++) // print all elements at same distance
            cout << (it->second)[i] << " ";

    cout << endl;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);

    verticalorder(root);

    return 0;
}