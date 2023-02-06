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
//this is all my code 
// nodes at k distance from root node
void nodesAtkDistance(Node *root, int k, vector<int> &ans)
{
    if (!root || k < 0)
    {
        return;
    }
    if (k == 0)
    {
        ans.push_back(root->data);
        return;
    }
    nodesAtkDistance(root->left, k - 1, ans);
    nodesAtkDistance(root->right, k - 1, ans);
    return;
}
bool ans(Node *root, vector<Node *> &a, int key)
{
    if (!root)
        return false;
    a.push_back(root);
    if (root->data == key)
        return true;
    if (ans(root->left, a, key) || ans(root->right, a, key))
        return true;
    a.pop_back();
    return false;
}
// code from course
//not completed yet
void printSubTreeNodes(Node*root,int k){
    if(!root||k<0)return ;
    if(k==0){
        cout<<root->data<<" ";
        return ;
    }
    printSubTreeNodes(root->left,k-1);
    printSubTreeNodes(root->right,k-1);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    root->right->right->right->right=new Node(9);
    //this is drive code of my code
    vector<Node *> res;
    ans(root, res, 7);
    cout<<"Ancestors of given node:";
    for (auto it : res)
    {
        cout << it->data << " ";
    }
    cout << endl;
    int k=3;
    reverse(res.begin(),res.end());
        Node*prev=NULL;
    for (auto it : res)
    {
        vector<int> an;
        if(!prev)
        nodesAtkDistance(it,k,an);
        else if(it->left==prev)
        nodesAtkDistance(it->right,k-1, an);
        else if(it->right==prev)
        nodesAtkDistance(it->left,k-1,an);
        k--;
        cout<<"Nodes at k distance from this ancestor:"<<it->data<<"->";
    for (auto yt : an)
        cout << yt << " ";
    cout << endl;
        if(k==0)
        break;
        prev=it;
    }
    //end of my driver code

    return 0;
}