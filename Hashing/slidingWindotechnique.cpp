#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[] = {-2, 10, 1, 3, 2, -1, 4, 5};
    int k = 2, sum = 0;

    // first compute sum till k elements
    for (int i = 0; i < k; i++)
        sum += a[i];

    int MIN = sum;
    // now traverse till n-1 elements and subtracat ith and add i+k-1th element
    for (int i = 1; i < 8+k-1; i++)
    {
        sum -= a[i - 1];
        sum += a[i + k - 1];
        MIN = min(sum, MIN);
    }

    cout << MIN << endl;
    return 0;
}