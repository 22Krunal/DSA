#include <bits/stdc++.h>

using namespace std;
struct node
{
    int data;
    struct node *prev;
    struct node *nxt;
};
static int total = 0;
node *insert(node *&head, int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->nxt = NULL;
    tmp->prev = NULL;
    if (head == NULL)
    {
        ++total;
        head = tmp;
        tmp->prev = head;
        tmp->nxt = NULL;
        return head;
    }
    struct node *n = head;
    int i = 1;
    while (i != total)
    {
        n = n->nxt;
        i++;
    }
    n->nxt = tmp;
    tmp->prev = n;
    tmp->nxt = NULL;
    total++;
    return head;
}
void view(node *&head)
{
    int i = 0;
    struct node *n = head;
    while (i < total)
    {
        cout << n->data << "->";
        n = n->nxt;
        i++;
    }
    cout << "NULL" << endl;
    return;
}
bool search(node *&head, int data)
{
    struct node *n = head;
    int i = 0;
    while (i != total)
    {
        if (n->data == data)
            return true;
        n = n->nxt;
        i++;
    }
    return false;
}
node *Delete(node *&head, int data)
{
    if (head->data == data)
    {
        head = head->nxt;
        head->prev = NULL;
        total--;
        return head;
    }
    int i = 0;
    struct node *tmp = head;
    while (i < total)
    {
        if (tmp->nxt->data == data)
        {
            cout << data << endl;
            if (tmp->nxt->nxt == NULL)
            {
                tmp->nxt = NULL;
                total--;
                return head;
            }
            tmp->nxt = tmp->nxt->nxt;
            tmp->nxt->prev = tmp;
            //  tmp=tmp->nxt;
            //  tmp->prev=NULL;
            total--;
            return head;
        }
        i++;
        tmp = tmp->nxt;
    }
    cout << data << " is not Present in the list" << endl;
    return head;
}
int main()
{
    struct node *head = NULL;
    head = insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    view(head);
    cout << search(head, 3) << " " << search(head, 10) << endl;
    head = Delete(head, 3);
    view(head);
    head = Delete(head, 7);
    view(head);
    head = Delete(head, 1);
    view(head);

    return 0;
}