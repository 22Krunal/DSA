#include<bits/stdc++.h>


using namespace std;

struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isPresent(Node*root,int key){
    if(!root){
        return false;
    }
    if(root->data == key ){
        return true;
    }
    if(root->data > key){
        return isPresent(root->left,key);
    }
    return isPresent(root->right,key);
}
bool search(Node*root,int key){
    if(!root){
        return false;
    }
    while(root){
        if(root->data == key){
            return true;
        }
        if(root->data > key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return false;
}
Node *insert(Node*root,int key){
    if(!root){
        return new Node(key);
    }
    if(root->data > key){
        root->left = insert(root->left,key);
    }
    else if(root->data < key){
        root->right = insert(root->right,key);
    }
    return root;
}
Node *Insert(Node*root,int key){
    if(!root){
        return new Node(key);
    }
    
    Node* t = NULL;
    Node* Root = root;
    while(root){
        t = root;
        if(root->data == key){
            return Root;
        }
        if(root->data > key){
            root = root->left;
        }
        else{
            root = root->right ;
        }
    }
    if(t->data > key){
        t->left = new Node(key);
    }else{
        t->right = new Node(key);
    }
    return Root;
}
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
void preorder(Node*root){
    if(!root){
        return ;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    Node*root = insert(root,10);
    insert(root,20);
    preorder(root);
    cout<<"";
    return 0;
}