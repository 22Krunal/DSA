#include <bits/stdc++.h>

using namespace std;

int main()
{

    int a[] = {5, 4, 2, 7};

    // creating minheap
    priority_queue<int, vector<int>, greater<int>> pmin;

    for (int i = 0; i < 4; i++)
        pmin.push(a[i]);

    int cost = 0;
    // pop top two elements and add to cost and add their sum to min heap
    while (pmin.size() > 1)
    {
        int temp = pmin.top();
        pmin.pop();
        temp += pmin.top();
        pmin.pop();
        pmin.push(temp);
        cost += temp;
    }
    cout << cost << endl;
    return 0;
}