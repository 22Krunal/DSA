#include<bits/stdc++.h>


using namespace std;
struct Node{
    int data ;
    struct Node*next;
    Node(int val){
        data = data;
        next = NULL;
    }
};
// keep track of list 
Node*head = NULL;
Node*tail = NULL; 
Node*insert(int data){
    Node*tmp = new Node(data);
    if(!head){
        head = tmp;
        tail = tmp;
    }
    else{
        tail->next = tmp;
        tail = tmp;
    }
    return head;
}
bool search(int key){
    Node*tmp = head;
    while(tmp){
        if(tmp->data == key){
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}
Node* reverse(Node*head){
    Node*prev = NULL;
    Node*curr = head;
    Node*nxt = NULL;
    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
    return head;
}
Node* reverse(Node*head, int k){
    Node* prev = NULL;
    Node*curr = head;
    Node*nxt = NULL;
    int i = k;
    while(curr && i){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        i--;
    }
    if(!nxt){
        head->next = reverse(nxt,k);
    }
    return prev;
}
Node* Delete(int key){
    Node*tmp = NULL;
    if(head->data == key){
        tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
    Node*n = head;
    Node*nxt = head->next;
    while(n&&nxt){
        if(nxt->data == key){
            n->next = nxt->next;
            tmp = nxt;
            n = n->next;
            nxt = nxt->next;
            free(tmp);
            return head;
        }
        n = n->next;
        nxt = nxt->next;
    }
    return head;
}
// if cycle present then return meeting point else return NULL
Node* detectCycle(Node*head){
    Node*slow = head;
    Node*fast = head;
    while(slow && fast->next){
        fast = fast->next;
        if(fast->next == slow->next){
            return fast;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return NULL;
}
//remove function first cheack weather loop is present or not 
Node *removeCycle(Node*head){
    Node*tmp = detectCycle(head);

    if(!tmp){ // no cylce present
        return head;
    }
    Node*slow = head;

    while(slow && tmp){
        slow = slow->next;
        if(tmp->next == slow->next){
            slow->next = NULL;
        }
        tmp = tmp->next;
    }
    return head;
}
int main(){

    cout<<"";
    return 0;
}