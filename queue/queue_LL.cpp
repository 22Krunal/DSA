#include <bits/stdc++.h>

using namespace std;
struct node
{
    int data;
    struct node *next;
};
class Queue
{
    struct node *front;
    struct node *rare;

public:
    Queue();
    void push(int);
    int peek();
    void pop();
    bool isEmpty();
};
Queue::Queue()
{
    front = NULL;
    rare = NULL;
}
bool Queue::isEmpty()
{
    if (front == NULL)
        return true;
    return false;
}
void Queue::push(int data)
{
    struct node *Newnode = (struct node *)malloc(sizeof(struct node));
    Newnode->data = data;
    Newnode->next = NULL;
    if (front == NULL)
    {
        front = Newnode;
        rare = Newnode;
        return;
    }
    rare->next = Newnode;
    rare = Newnode;
    rare->next = NULL;
    return;
}
void Queue::pop()
{
    if (isEmpty())
    {
        cout << "Stack is Empty!!!" << endl;
        return;
    }
    front = front->next;
    return;
}
int Queue::peek()
{
    if (isEmpty())
    {
        cout << "Stack is Empty!!!" << endl;
        return -1;
    }
    return front->data;
}
int main()
{
    class Queue q;
    q.pop();
    q.push(1);
    cout << q.peek() << endl;
    q.push(2);
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;

    return 0;
}