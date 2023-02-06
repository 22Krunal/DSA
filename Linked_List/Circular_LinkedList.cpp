// check once for insertat position
#include <bits/stdc++.h>

using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
static int c = 0;
void insert()
{
    c++;
    int data;
    cout << "Enter the data:";
    cin >> data;
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = NULL;
    if (head == NULL)
    {
        head = tmp;
        tmp->next = head;
        tail = tmp;
        // tail->next = head;
        return;
    }
    tail->next = tmp;
    tmp->next = head;
    // tail->next = head;
    tail = tmp;
    return;
}
void Delete()
{
    int data;
    cout << "Enter the data:";
    cin >> data;
    struct node *tmp = head;
    if (head->data == data)
    {
        tmp = tmp->next;
        head = tmp;
        tail->next = tmp;
        c--;
        cout << data << " has been deleted from the list\n";

        return;
    }
    int i = 0;
    while (i < c)
    {
        if (tmp->next->next == head && tmp->next->data == data)
        {
            tmp->next = head;
            tail = tmp;
            c--;
            cout << data << " has been deleted from the list\n";
            return;
        }
        if (tmp->next->data == data)
        {
            c--;
            tmp->next = tmp->next->next;
            cout << data << " has been deleted from the list\n";
            return;
        }
        i++;
        tmp = tmp->next;
    }
    cout << data << " is not Present in the list\n";
}
void view()
{
    struct node *tmp = head;
    int i = 0;
    while (i != c)
    {
        cout << tmp->data << " ->";
        tmp = tmp->next;
        i++;
    }
    cout << "\n";
}
void search()
{
    int data, i = 0;
    cout << "Enter the Data:";
    cin >> data;
    struct node *tmp = head;
    while (i < c)
    {
        i++;
        if (tmp->data == data)
        {
            cout << data << " is Present in the List\n";
            return;
        }
        tmp = tmp->next;
    }
    cout << data << " is not Present in the List\n";
}
void insertAt()
{
    int pos, data;
    cout << "Enter the position:";
    cin >> pos;
    cout << "Enter the data:";
    cin >> data;
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = NULL;
    if (pos == 0)
    {
        tmp->next = head->next;
        head = tmp;
        tail->next = head;
        c++;
        return;
    }
    if (pos == c)
    {
        tail->next = tmp;
        tmp->next = head;
        tail = tmp;
        c++;
        return;
    }
    int i = 0;
    struct node *n = head;
    while (i < c)
    {

        i++;
        if (i == c)
        {
            n->next = tmp;
            n = n->next;
            tmp->next = n;
            c++;
            return;
        }
        n = n->next;
    }
}
int main()
{
    int n;
    do
    {
        cout << "0.To Exit" << endl
             << "1.To Insert" << endl
             << "2.To Delete" << endl
             << "3.To Search" << endl
             << "4.To View" << endl
             << "5.To Insert at Position" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            search();
            break;
        case 4:
            view();
            break;
        case 5:
            insertAt();
            break;
        }

    } while (n != 0);
    return 0;
}