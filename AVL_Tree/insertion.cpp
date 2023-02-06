#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node*left;
    struct Node*right;
    int height ;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
        height = 1;
    }
};
Node*root = NULL;
//return height of node
int Height(Node*p){
    if(!p){
        return 0;
    }
    int lh = 0, rh = 0;
    if(p->left){
        lh = p->left->height;
    }
    if(p->right){
        rh = p->right->height;
    }
    return max(lh,rh) + 1;
}
// return balance factor(left height - right height)
int balanceFactor(Node*p){
    if(!p){
        return 0;
    }
    int lh = 0 , rh = 0;
    if(p->left){
        lh = p->left->height;
    }
    if(p->right){
        rh = p->right->height;
    }
    return (lh-rh);
}
bool isBalanced(Node*p){
    if(abs(balanceFactor(p)) <= 1){
        return true;
    }
    return false;
}
//Rotations 
Node* LLrotation(Node* p){
    cout << "LL rotation : " << endl;
   
    Node* pl = p->left;
    Node* plr = pl->right;
   
    pl->right = p;
    p->left = plr;

    p->height = Height(p);
    pl->height = Height(pl);

    if(root == p){
        root = pl;
    }
    return pl;
}
Node* LRrotation(Node*p){
    cout << "LR rotation : " << endl;

    Node* plr = p->left->right;
    Node* pl = p->left;
    Node* l = plr->left;
    Node* r = plr->right;
    
    pl->right = l;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;

    p->height = Height(p);
    plr->height = Height(plr);
    pl->height = Height(pl);

    // l->height = Height(l);
    // r->height = Height(r);
    if(root == p){
        root = plr;
    }
    return plr;
}
Node* RRrotation(Node*p){
    cout << "RR rotation : " << endl;
    
    Node*pr = p->right;
    p->right = pr->left;
    pr->left = p;
    
    pr->height = Height(pr);
    p->height = Height(p);
    
    if(root == p){
        root = pr;
    }
    return pr;
}
Node* RLrotation(Node*p){
    cout << "RL rotation : " << endl;
    
    Node* prl = p->right->left;
    Node* pr = p->right;
    Node* l = prl->left;
    Node* r = prl->right;
    
    prl->left = p;
    prl->right = pr;
    p->right = l;
    pr->left = r;
    
    p->height = Height(p);
    prl->height = Height(prl);
    pr->height = Height(pr);
    // l->height = Height(l);
    // r->height = Height(r);
    if(root == p){
        root = prl;
    }
    return prl;   
}
Node* Rotate(Node*p){
    int Root = balanceFactor(p);
    int Left = balanceFactor(p->left);
    int Right = balanceFactor(p->right);
    if(Root == 2 && Left == 1){
        return LLrotation(p);
    }
    if(Root == 2 && Left == -1){
        return LRrotation(p);
    }
    if(Root == -2 && Right == -1){
        return RRrotation(p);
    }
    if(Root == -2 && Right == 1){
        return RLrotation(p);
    }
    return p;
}
Node* insert(Node*p,int data){
     if(!p){
         return new Node(data);
     }
     if(p->data < data){
        p->right = insert(p->right,data);
     }
    else if(p->data >data){
        p->left = insert(p->left,data);
     }
     p->height = Height(p);
     if(!isBalanced(p)){
        cout <<p->data << " Imbalance : " << balanceFactor(p) << endl;
        p = Rotate(p);
     }
     return p;
}
void inorder(Node*p){
    if(!p)return ;
    inorder(p->left);
    cout<<p->data<<" " << p->height << " "<< balanceFactor(p) << endl;
    inorder(p->right);
}

Node* Delete(Node* p,int val){
    if(!root){
        return NULL;
    }
    if(root->data > val){
        root->left = Delete(root->left,val);
    }
    else if(root->data < val){
        root->right = Delete(root->right,val);
    }
    else{
        // no child
        if(!root->left && !root->right){
            // Node* tmp = root;
            free(root);
            return NULL;
        }
        if(root->left && root->right){
            
        }
    }

}
int main(){

    // LL rotation
    // root = insert(root,10);
    // insert(root,5);
    // insert(root,2);
    // inorder(root);

    // RR rotation
    root = insert(root,10);
    insert(root,15);
    insert(root,20);
    inorder(root);

    // LR rotation 
    // root = insert(root,40);
    // insert(root,20);
    // insert(root,50);
    // insert(root,10);
    // insert(root,60);
    // insert(root,30);
    // insert(root,5);
    // insert(root,25);
    // insert(root,36);
    // cout << "Before inserting 27 : " << endl;
    // inorder(root);
    // // cout << endl;
    // insert(root,27);
    // cout << "After inserting 27 :" << endl;
    // inorder(root);
    // // cout << endl;

    //RL rotation 

    // root = insert(root,50);
    // insert(root,70);
    // insert(root,40);
    // insert(root,30);
    // insert(root,60);
    // insert(root,65);
    // insert(root,59);
    // inorder(root); 
    return 0;
}