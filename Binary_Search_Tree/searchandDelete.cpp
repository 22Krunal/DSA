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
Node *search(Node *root, int key)
{
    if (!root)
        return NULL;
    if (root->data == key)
        return root;
    if (root->data > key)
        return search(root->left, key);
    if (root->data < key)
        return search(root->right, key);
}
Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left)
    {
        curr = curr->left;
    }
    return curr;
}
Node *deleteInBST(Node *root, int key)
{
    if (!root)
        return NULL;
    if (root->data > key)

        root->left = deleteInBST(root->left, key);

    else if (root->data < key)
        root->right = deleteInBST(root->right, key);

    else if (root->data == key)
    {
        // Node with Zero child
        if (!root->left && !root->right)
        {
            free(root);
            return NULL;
        }
        // Node with one child
        if (!root->left)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        if (!root->right)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Node with two child
        Node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }
    return root;
}

// another way to delete the element from BST
int Height(Node*root){
    if(!root){
        return 0;
    }
    return max(Height(root->left),Height(root->right)) + 1;
}
// returns inorder predecessor
Node* inPre(Node*root){

    while(root && root->left){
        root = root->left;
    }
    return root;
}
// returns inorder successor
Node* inSuc(Node*root){

    while(root && root->right){
        root = root->right;
    }
    return root;
}
Node* Delete(Node*root,int key){
    if(!root){
        return NULL;
    }
    if(root->data > key){
        root->left = Delete(root->left, key);
    }
    else if(root->data < key){
        root->right = Delete(root->right, key);
    }
    else{
        // no child 
        if(!root->left && !root->right){
            free(root);
            return NULL;
        }
        // two child 
        if(root->left && root->right){
            if(Height(root->left) > Height(root->right)){
                Node* tmp = inSuc(root->right);
                root->data = tmp->data;
                root->right = Delete(root->right,tmp->data);
                return root;
            }
            else {
                Node* tmp = inPre(root->left);
                root->data = tmp->data;
                root->left = Delete(root->left,tmp->data);
                return root;
            }
        }
        // one child 
        if(!root->left){
            Node* tmp = root;
            root = root->right;
            free(tmp);
            return root;
        }
        if(!root->right){
            Node* tmp = root;
            root = root->left;
            free(tmp);
            return root;
        }
    }
    return root;
}
// process completed  
int main()
{
    Node *root = NULL;
    root = insert(root, 5);
    insert(root, 2);
    insert(root, 11);
    insert(root, 9);
    insert(root, 10);
    insert(root, 7);
    insert(root, 8);
    insert(root, 6);
    cout << search(root, 7) << endl;
    cout << search(root, 0) << endl;
    inorder(root);
    cout << endl;
    root = Delete(root, 9);
    inorder(root);
    return 0;
}