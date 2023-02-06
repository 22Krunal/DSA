#include <bits/stdc++.h>

using namespace std;

// creating max and min heap
priority_queue<int, vector<int>> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;

void insert(int x)
{

    // size of max heap and min heap is equal
    if (maxheap.size() == minheap.size())
    {
        if (maxheap.size() == 0)
            maxheap.push(x);
        else
        {
            // if x is bigger than max.top than push it in max heap else in min heap
            
            if (x < maxheap.top())
                minheap.push(x);
            else
                maxheap.push(x);
        }
    }
    else
    {
        if (maxheap.size() > minheap.size())
        {
            // case 1:size of max heap is greater than min heap
            if (x >= maxheap.top())
                minheap.push(x);
            else
            {
                int temp = maxheap.top();
                minheap.push(temp);
                maxheap.push(x);
            }
        }
        else
        {
            // case 2:size of min heap is greater than max heap
            if (x <= minheap.top())
                maxheap.push(x);
            else
            {
                int temp = minheap.top();
                maxheap.push(temp);
                minheap.push(x);
            }
        }
    }
}
float meadian()
{
    if (maxheap.size() == minheap.size())
        return (maxheap.top() + minheap.top()) / 2;

    return maxheap.size() > minheap.size() ? maxheap.top() : minheap.top();
}
int main()
{
    int a[] = {10, 15, 21, 10, 10, 10};

    // inserting element one by one in heap and printing median after every insertion
    for (auto it : a)
    {
        insert(it);
        cout << meadian() << " ";
    }
    cout << endl;

    return 0;
}