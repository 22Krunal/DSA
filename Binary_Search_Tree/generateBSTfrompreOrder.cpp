#include<bits/stdc++.h>


using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node (int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node * insertInBST(Node * root, int key){
    if(!root){
        return new Node(key);
    }
    Node * tmp = NULL;
    Node * n = root;
    while(n){
        tmp = n;
        if(n->data == key){ // key already present in BST
            return root;
        }
        if(n->data > key){
            n = n->left;
        }
        else if(n->data < key){
            n = n->right;
        }
    }
    if(tmp->data > key){
        tmp->left = new Node(key);
    }
    else{
        tmp->right = new Node(key);
    }
    return  root;
}
void Inorder(Node* root){
    if(!root){
        return ;
    }
    stack <Node*> st;

    while(root || !st.empty()){
        if(root){
            cout << root->data << " ";
            st.push(root);
            root = root->left;
        }
        else{
            root = st.top();
            st.pop();
            root = root->right;
        }
    }
    return ;
}
int search(vector<int>& in,int key, int l, int r){
    for(int i=l; i<=r; i++){
        if(in[i] == key){
            return i;
        }
    }
}
Node * buildBST(vector<int>& pre,vector<int> & in, int l, int r){
    if(l > r){
        return NULL;
    }
    static int idx = 0;
    int curr = pre[idx];
    idx ++;
    int pos = search(in,curr,l,r);
    Node * root = new Node(curr);

    root->left = buildBST(pre,in,l,pos-1);
    root->right = buildBST(pre,in,pos+1, r);

    return root; 
}
int main(){
    vector<int> pre = {30,20,10,15,25,40,50,45};
    vector<int> in = pre;
    sort(in.begin(), in.end());
    Node*root = buildBST(pre,in,0,7);
    cout << "Inorder : " ;
    Inorder(root);
    cout << endl;
    return 0;
}