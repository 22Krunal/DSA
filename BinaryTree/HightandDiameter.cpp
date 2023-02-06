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
int height(struct node *root)
{
    if (!root)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
int diameter(struct node *root)
{
    if (!root)
        return 0;
    int lheight = height(root->left);
    int rheight = height(root->right);
    int currdiameter = lheight + rheight + 1;

    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
    return max(currdiameter, max(ldiameter, rdiameter));
}
// optimize approch so that we do not have to calculate the height of tree every time
int caldiameter(struct node*root,int *height){
       if(!root)
       {
           *height=0;
           return 0;
       }
       int lh=0,rh=0;
       int ldiameter=caldiameter(root->left,&lh);
       int rdiameter=caldiameter(root->right,&rh);

        int currdiameter=lh+rh+1;
       *height=max(rh,lh)+1;
      return max(currdiameter,max(ldiameter,rdiameter));
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
    root->right->left->right = new node(8);
    cout << "Height:: " << height(root) << endl;
    cout << "Diameter:: " << diameter(root) << endl;
    int height=0;
    cout << "Diameter:: " << caldiameter(root,&height) << endl;

    return 0;
}