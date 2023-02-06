// pop function is yet to complete
#include <bits/stdc++.h>
using namespace std;
class Queue
{
    stack<int> stack1;

public:
    void push(int);
    void pop();
    int peek();
    bool isEmpty();
};
bool Queue::isEmpty()
{
    if (stack1.empty())
        return true;
    return false;
}
void Queue::push(int data)
{
    stack1.push(data);
    return;
}
void Queue::pop()
{
    if (isEmpty())
    {
        // cout << "Queue is Empty!!!" << endl;
        return;
    }
     int x=stack1.top();
     stack1.pop();
     
}

int Queue::peek()
{
    if (isEmpty())
    {
        cout << "Stack is Empty!!!" << endl;
        return -1;
    }
    while (!stack1.empty())
    {
        stack2.push(stack1.top());
        stack1.pop();
    }
    int top = stack2.top();
    while (!stack2.empty())
    {
        stack1.push(stack2.top());
        stack2.pop();
    }
    return top;
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
