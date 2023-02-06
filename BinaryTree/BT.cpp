#include<bits/stdc++.h>


using namespace std;

struct Node{
    int data;
    struct Node*left;
    struct Node*right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// returns the Height of the binary tree
int Height(Node*root){
    if(!root){
        return 0;
    }
    return max(Height(root->left),Height(root->right))+1;
}
// returns Diameter of tree
int Diameter(Node*root){
    if(!root){
        return 0;
    }
    int lh = Height(root->left);
    int rh = Height(root->right);
    int currh  = max(lh,rh) + 1;
    int currd = lh + rh + 1;

    return max({currd,Diameter(root->left),Diameter(root->right)});
}
// optimized version of diameter fun
int Diameter(Node*root,int *h){
    if(!root){
        *h = 0;
        return 0;
    }
    int lh = 0 , rh = 0;
    int ld = Diameter(root->left,&lh);
    int rd = Diameter(root->right,&rh);
    *h = max(lh,rh) + 1;
    int currd = lh+rh+1;
    return max({ld,rd,currd});
}
// returns the count of nodes
int count(Node*root){
    if(!root){
        return 0;
    }
    return count(root->left)+count(root->right)+1;
}
// count leaf nodes 
int lcount(Node*root){
    if(!root){
        return 0;
    }
    if(!root->left && !root->right){
        return 1;
    }
    return lcount(root->left) + lcount(root->right) + 1;
}
// count none leaf node
int nlcount(Node*root){
    if(!root){
        return 0;
    }
    if(!root->left && !root->right){
        return 0;
    }
    return nlcount(root->left) + nlcount(root->right) + 1;
}
// return Lowest comman ancestor data 
int LCA(Node*root,int n1,int n2){
    if(!root){
        return -1;
    }

    if(root->data == n1 || root->data == n2){
        return root->data;
    }

    int left = LCA(root->left,n1,n2);
    int right = LCA(root->right,n1,n2);

    if(left != -1 && right != -1){
        return root->data;
    }
    if(left == -1 && right == -1){
        return -1;
    } 
    if(right != -1){
        return LCA(root->right,n1,n2);
    }
    return LCA(root->left,n1,n2);
}
// return LCA node
Node* Lca(Node*root,int n1,int n2){
    if(!root){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* left = Lca(root->left,n1,n2);
    Node* right = Lca(root->right,n1,n2);

    if(left && right){
        return root;
    }
    if(!left && !right){
        return NULL;
    } 
    if(!left){
        return Lca(root->right,n1,n2);
    }
    return Lca(root->left,n1,n2);
}
// traversals 
void inorder(Node*root){
    if(!root){
        return ;
    }
    inorder(root->left);
    cout << root->data << " " ;
    inorder(root->right);
}
void postorder(Node*root){
    if(!root){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " " ;
}
void preorder(Node*root){
    if(!root){
        return ;
    }
    cout << root->data << " " ;
    preorder(root->left);
    preorder(root->right);
}
void levelOrder(Node*root){
    if(!root){
        return ;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node*temp = q.front();
        q.pop();
        if(temp){
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}
void zigzag(Node*root){

}
void iPreOrder(Node*root){
    if(!root){
        return ;
    }
    stack<Node*> st;
    while(!root || !st.empty()){
        if(!root){
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
// build tree from preorder and inorder
int pos(int in[],int l, int r, int target){
    for(int i=l; i<r; i++){
        if(in[i] == target){
            return i;
        }
    }
    return -1;
}
Node* buildTree(int pre[],int in[], int n, int l, int r){
    static int idx = 0;
    if(l > r){
        return NULL;
    }
    int curr = pre[idx];
    idx ++;
    int p = pos(in,l,r,curr);
    Node*root = new Node(curr);
    if(l == r){
        return root;
    }
    root->left = buildTree(pre,in,n,l,p-1);
    root->right = buildTree(pre,in,n,p+1,r);
    return root;
}
int main(){
    
    cout<<"";
    return 0;
}