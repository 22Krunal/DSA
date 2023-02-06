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
    }
};
int search(int a[], int data, int start, int end)
{
    for (int i = start; i <= end; i++)
    {

        if (a[i] == data)
            return i;
    }
    return -1;
}
node *buildTree(int postorder[], int inorder[], int start, int end)
{
    static int index = 5;
    if (start > end || index < 0)
        return NULL;
    int curr = postorder[index];
    index--;
    // cout <<"start=>"<< start << " end=> " << end << " index=> "<<index<<" root->data ";
    node *root = new node(curr);
    // cout<<root->data<<endl;
    if (start == end)
        return root;
    int pos = search(inorder, curr, start, end);
    root->right = buildTree(postorder, inorder, pos + 1, end);
    root->left = buildTree(postorder, inorder, start, pos - 1);
    return root;
}

void inorder(struct node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    int postorder[] = {3, 4, 2, 6, 5, 1};
    int Inorder[] = {3, 2, 4, 1, 6, 5};
    node *root = buildTree(postorder, Inorder, 0, 5);
    inorder(root);
    return 0;
}