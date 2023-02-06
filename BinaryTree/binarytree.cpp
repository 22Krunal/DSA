#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node*left;
    struct node*right;
    node(int value){
        data=value;
        left=NULL;
        right=NULL;
    };
};

// recursive version
void preorder(struct node *root){
    if(!root)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
//Iterative version
void iPreOrder(struct node *root){
    if(!root){
        return ;
    }
    
    stack <node*> st;
    while(root|| !st.empty()){
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
    
}
//recursive version
void postorder(struct node*root){
    if(!root)
    return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
//Iterative version still uncomplete
void iPostOrder(struct node*root){
    if(!root){
        return ;
    }
    stack<node*> st;
    stack<node*> s;
    while(root || !st.empty()){
        if(root){
            st.push(root);
            root = root->left;
        }
        else{
            root = st.top();
            if(root>0){
                st.pop();
                s.push(root);
            root = root->right;
            }
            else{
                root = s.top();
                s.pop();
                cout << root->data << " ";
                root = NULL;
            }
            
            // cout << root->data << " ";
        }
    }
}
//recursive version
void Inorder(struct node*root){
    if(!root )return ;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
//Iterative version
void iInOrder(struct node*root){
    if(!root){
        return ;
    }
    stack<node*> st;
    while(root || !st.empty()){
        if(root){
            st.push(root);
            root = root->left;
        }
        else{
            root = st.top();
            cout << root->data << " ";
            st.pop();
            root = root->right;
        }
    }
}
int main(){
    struct node *root=new node(1);
    root->right=new node(3);
    root->left=new node(2);
    root->left->right=new node(5);
    root->left->left=new node(4);
    root->right->left=new node(6);
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
    cout << "IpreOrder: ";
    iPreOrder(root);
    cout << endl;
    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;
    cout <<"IpostOrder: ";
    iPostOrder(root);
    cout << endl;
     cout<<"Inorder: ";
    Inorder(root);
    cout<<endl;
    cout <<"IinOrder : ";
    iInOrder(root);
    cout << endl;
    /*
      1
     / \
    3   2
   / \  /
  5   4 6
    */

     
    return 0;
}