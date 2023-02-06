#include<bits/stdc++.h>


using namespace std;

struct Node{
    int data;
    struct Node*left;
    struct Node*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
}
};


int height(Node*root){
    if(!root){
        return 0;
    }
    return max(height(root->left),height(root->right)) + 1;
}
int Diameter(Node*root, int *height){
    if(!root){
        *height = 0;
        return 0;
    }

    int lh=0, rh=0;
   
    
    int lDiameter = Diameter(root->left, &lh);
    int rDiameter = Diameter(root->right,&rh);
    int currdiameter = lh + rh +1;
    
    *height = max(lh, rh)+1;

    return max( currdiameter,max(lDiameter,rDiameter));
}

int diameter(Node*root, int *res){
    if(!root){
        return 0;
    }

    int l = diameter(root->left,res);
    int r = diameter(root->right,res);

    int temp = 1 + max(l,r);

    int Ans = max(temp,1+l+r);

    *res = max(Ans,*res);

    return temp;
}
Node*LCA(Node*root, int n1, int n2){
    if(!root){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }
    Node* left = LCA(root->left,n1,n2);
    Node* right = LCA(root->right,n1,n2);
    
    if(left&&right){
        return root;
    }
    if(!left&&!right){
        return NULL;
    }
    if(!left){
        return LCA(root->right,n1,n2);
    }
    return LCA(root->left,n1,n2);
    
}
int main(){
    
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int height = 0;
    cout<<Diameter(root,&height)<<endl;

    Node*lca= LCA(root,4,5);
    cout<<lca->data<<endl;

    int res = INT_MIN;
    diameter(root,&res);
    cout << res <<endl;
    
    return 0;
}