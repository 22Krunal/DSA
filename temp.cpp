#include<bits/stdc++.h>

using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node*sortedArrayToBST(int arr[], int l, int r){
    if(l >= r){
        return NULL;
    }
    int mid = (l+r)/2;

    Node* root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr,l,mid);
    root->right = sortedArrayToBST(arr,mid+1,r);

    return root;
}

void inorder(Node* root){
    if(!root){
        return ;
    }
    stack<Node*> st;
    while(root || !st.empty()){
        if(root){
            st.push(root);
            root = root->left;
        }
        else{
            root = st.top();
            st.pop();
            if(root){
            cout << root->data << " ";
                root = root->right;
            }
        }
    }
}
void print(Node*root){
    if(!root){
        return ;
    }
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    Node* root = sortedArrayToBST(arr,0,8);
    print(root);
    cout << endl;
    inorder(root);
    return 0;
}