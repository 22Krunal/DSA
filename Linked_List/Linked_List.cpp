// Merge part is still remainnig
#include <bits/stdc++.h>

using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *head1 = NULL;
node *insert(node *&head, int data)
{

    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->next = NULL;
    tmp->data = data;
    if (head == NULL) // First node of the list
    {
        head = tmp;
        return head;
    } // other node to append at list
    struct node *n = head;
    while (n->next != NULL)
    {
        n = n->next;
    }
    n->next = tmp;
    tmp->next = NULL;
    return head;
}
bool search(node *&head)
{
    int data;
    cout << "Enter the data:";
    cin >> data;
    struct node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data == data) // travrse through list till end to find data
            return true;

        tmp = tmp->next;
    }
    return false;
}
node *Delete(node *&head, int data)
{

    struct node *tmp = head;
    if (tmp->data == data) // if it is head
    {
        head = tmp->next;
       struct node*t=tmp;
       delete t;
        return head;
    }
    while (tmp->next != NULL) // travse till end
    {

        if (tmp->next->data == data) // node between head and tail
        {
            tmp->next = tmp->next->next;
               struct node*t=tmp->next;
               delete t;
            return head;
        }
        tmp = tmp->next;
    }
    cout << data << " is not Present in the List\n";
    return head;
}
void view(node *&head)
{
    struct node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << "->";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
    return;
}
void insertAt(node *&head)
{
    int pos, data;
    cout << "Enter the position:";
    cin >> pos;
    cout << "\nEnter the data:";
    cin >> data;
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = NULL;
    if (pos == 0) // insert before head (new head)
    {
        tmp->next = head;
        head = tmp;
        return;
    }
    int i = 0;
    struct node *n = head;
    while (n != NULL)
    {
        ++i; // to count position

        if (i == pos)
        {
            tmp->next = n->next;
            n->next = tmp;
            return;
        }
        n = n->next;
    }
}
void reverse(node *&head)
{
    struct node *curentptr = head;
    struct node *previousptr = NULL;
    struct node *nextptr = NULL;
    while (curentptr != NULL)
    {
        nextptr = curentptr->next;
        curentptr->next = previousptr;
        previousptr = curentptr;
        curentptr = nextptr;
    }
    head = previousptr;
}
void makecycle(node *&head)
{
    int pos;
    cout << "Enter the position:";
    cin >> pos;
    struct node *tmp = head;
    struct node *n = head;
    while (n->next != NULL)
    {
        n = n->next;
    }
    int i = 0;
    while (i != pos)
    {

        tmp = tmp->next;
        i++;
    }
    n->next = tmp;
}
bool detectcycle(node *&head)
{
    struct node *fast = head;
    struct node *slow = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        if (fast->next == slow->next)
            return true;
        slow = slow->next;
    }
    return false;
}
void removecycle(node *&head)
{
    struct node *fast = head;
    struct node *slow = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    slow = head;
    while (slow->next != fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = NULL;
}
node *reverse_recursion(node *&head)
{
    // if (head->next == NULL)
    // {
    //     ne = head;
    //     return head;
    // }
    // struct node *newhead = reverse_recursion(head->next);
    // newhead->next = head;
    // head->next = NULL;
    // return head;
    // previous one also does the work but not return the newhead

    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct node *newhead = reverse_recursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
node *reverseknode(node *&head, int k)
{

    struct node *prev = NULL;
    struct node *curr = head;
    struct node *nxt;
    int i = 0;
    while (k != i && curr != NULL)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        i++;
    }
    if (nxt != NULL)
        head->next = reverseknode(nxt, k);
    return prev;
}
// node *last_k_nodesatfirst(node *&head,int k){ this is clearly working but not optimized
//          struct node*tmp=head;
//          struct node*newhead=NULL;
//          int i=0;
//          while(tmp->next!=NULL){  //counting total number of nodes
//              tmp=tmp->next;
//              i++;
//          }
//          i=i-k;
//          tmp=head;
//          while(i!=0){     //traves till just before new head
//              tmp=tmp->next;
//              i--;
//          }
//          newhead=tmp->next;
//          tmp->next=NULL; //making null the last elements next null
//          tmp=newhead;
//          cout<<newhead->data<<endl;
//          while(tmp->next!=NULL){ //traves through newhead till end
//              tmp=tmp->next;
//          }
//          tmp->next=head; //appending old list to new one
//          return newhead;
// }
node *last_k_nodesatfirst(node *&head, int k)
{
    struct node *newhead;
    struct node *newtail;
    struct node *tail = head;
    int length = 0;
    while (tail->next != NULL)
    { // calculate the length
        tail = tail->next;
        length++;
    }
    tail = head;
    int count = -1;
    while (tail->next != NULL)
    {
        if (length - k > count) // remembers the last element of newtail
            newtail = tail;
        if (length - k == count) // remember the first element of the newhead(head)
            newhead = tail;
        tail = tail->next;
        count++;
    }
    newtail->next = NULL; // making last element of newtail null
    tail->next = head;    // appending list with new one
    return newhead;       // returning new head
}
node *Merge(node *&head)
{

    struct node *n1 = head;
    struct node *newhead = NULL;
    head1 = insert(head1, 2);
    head1 = insert(head1, 10);
    head1 = insert(head1, 11);
    head1 = insert(head1, 12);
    head1 = insert(head1, 17);
    struct node *n2 = head1;

    while (n1 != NULL && n2 != NULL)
    {
        if (n1->data <= n2->data)
        {
            newhead = insert(newhead, n1->data);
               struct node*t=n1;
            n1 = n1->next;
       delete t;
        }
        else
        {
            newhead = insert(newhead, n2->data);
               struct node*t=n2;
            n2 = n2->next;
       delete t;
        }
    }
    struct node *n = newhead;
    if (n1 != NULL)
    {
        while (n->next != NULL)
            n = n->next;
        n->next = n1;
    }
    else if (n2 != NULL)
    {
        while (n->next != NULL)
            n = n->next;
        n->next = n2;
    }
    return newhead;
}
// not optimized
//  node *EvenafterOdd(node *&head)
//  {
//      struct node *tmp = head;
//      struct node *newhead = NULL;
//      struct node *last = NULL; // to remember the last node
//      while (tmp != NULL)
//      {
//          if ((tmp->data % 2) == 0)
//          { // if data is even than delete it and insert it new list
//              newhead = insert(newhead, tmp->data);
//              head = Delete(head, tmp->data);
//          }
//          else
//              last = tmp;
//          tmp = tmp->next;
//      }
//      last->next = newhead; // append new list to the original list
//      return head;
//  }
node *EvenafterOdd(node *&head)
{
    struct node *even = NULL;
    struct node *odd = head;
    struct node *tmp = NULL;
    while (odd->next != NULL)
    {
        cout << odd->data << " ";
        if (odd->data % 2 == 0)
        {
            if (even == NULL)
            {
                even = odd->next;
                tmp = odd;
                tmp->next = NULL;
            }
            else
            {
                tmp->next = odd->next;
                tmp = odd;
                tmp->next = NULL;
            }
            odd->next = odd->next->next;
        }
        else
            odd = odd->next;
    }
    odd->next = even;
    return head;
}
node *make_intersection(node *&head)
{
    head1 = NULL;
    head1 = insert(head1, 9);
    head1 = insert(head1, 12);
    head1 = insert(head1, 13);
    int pos = 3;
    struct node *n = head1;
    struct node *n1 = head;
    while (n->next != NULL)
        n = n->next;
    while (n1->next != NULL)
    {
        if (pos == 0)
        {
            n->next = n1;
            // return head;
        }
        pos--;
        n1 = n1->next;
    }
    view(head);
    view(head1);
    return head;
}
bool intersection(node *&head1, node *&head2)
{
    struct node *n = head2;
    while (n != NULL)
    {
        struct node *n1 = head1;
        while (n1 != NULL)
        {
            if (n1 == n)
                return true;
            n1 = n1->next;
        }
        n = n->next;
    }
         return false;
}
int main()
{
    int n, data;
    do
    {
        cout << "Enter the number" << endl
             << "0.To Exit" << endl
             << "1.To Insert" << endl
             << "2.To Search" << endl
             << "3.To Delete" << endl
             << "4.To View" << endl
             << "5.To Insert at position" << endl
             << "6.To Reverse the list" << endl
             << "7.To Make a Cycle" << endl
             << "8.To Detect a Cycle" << endl
             << "9.To Remove Cycle" << endl
             << "10.To Reverse the list with recursion" << endl
             << "11.To Reverse k Nodes" << endl
             << "12.To Append last k Nodes at Head" << endl
             << "13.To Make Even nodes after Odd nodes" << endl
             << "14.To Merge sorted LinkedLists" << endl
             << "15.To Make Intersection" << endl
             << "16.To check Intersection" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter data:";
            cin >> data;
            head = insert(head, data);
            break;
        case 2:
            if (search(head))
                cout << "Data is present in the list " << endl;
            else
                cout << "Data is not present in the list" << endl;
            break;
        case 3:

            cout << "Enter the data:";
            cin >> data;
            head = Delete(head, data);
            break;
        case 4:
            view(head);
            break;
        case 5:
            insertAt(head);
            break;
        case 6:
            reverse(head);
            break;
        case 7:
            makecycle(head);
            break;
        case 8:
            if (detectcycle(head))
                cout << "Cycle is Present in the List" << endl;
            else
                cout << "No,Cycle is Present in the List" << endl;
            break;
        case 9:
            removecycle(head);
            break;
        case 10:
            head = reverse_recursion(head);
            break;
        case 11:
            cout << "Enter the k: ";
            cin >> data;
            head = reverseknode(head, data);
            break;
        case 12:
            cout << "Enter the k: ";
            cin >> data;
            head = last_k_nodesatfirst(head, data);
            break;
        case 13:
            head = EvenafterOdd(head);
            break;
        case 14:
            head = Merge(head);
            break;
        case 15:
            head = make_intersection(head);
            break;
        case 16:
            cout << intersection(head, head1) << endl;
        }

    } while (n != 0);
    return 0;
}
