#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int front;
    int rare;
    int size;
    int *Que;

public:
    Queue();
    void Enqueue(int);
    void Dequeue();
    int peek();
    bool isEmpty();
};
Queue::Queue()
{
    cout << "Enter the size:";
    cin >> size;
    front = 0;
    rare = -1;
    Que = (int *)malloc(size * sizeof(int));
}

bool Queue::isEmpty()
{
    if (front > rare || rare == -1)
        return true;
    return false;
}

void Queue::Enqueue(int data)
{
    if (rare == size - 1)
    {
        cout << "Overflow!!!" << endl;
        return;
    }
    rare++;
    Que[rare] = data;
    return;
}

void Queue::Dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!!!" << endl;
        return;
    }
    front++;
    return;
}

int Queue::peek()
{
    if (isEmpty())
    {
        cout << "Queue is Empty!!!" << endl;
        return INT_MIN;
    }
    return Que[front];
}

int main()
{
    class Queue Q;
    Q.Enqueue(1);
    cout << Q.peek();
    Q.Dequeue();
    Q.Enqueue(2);
    cout << Q.peek();
    Q.Enqueue(3);
    cout << Q.peek();
    Q.Enqueue(4);
    cout << Q.peek();
    Q.Enqueue(5);
    Q.Dequeue();
    cout << Q.peek();
    return 0;
}