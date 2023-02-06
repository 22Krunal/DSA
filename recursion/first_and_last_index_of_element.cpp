#include <bits/stdc++.h>
using namespace std;
int Last(int a[], int n, int key)
{
    if (n == 0)
        return -1;
    if (a[n - 1] == key)
        return n;
    return Last(a, n - 1, key);
}
int First(int a[], int n, int i, int key)
{
    if (n == 0)
        return -1;
    if (a[i] == key)
        return i + 1;
    return First(a, n - 1, i + 1, key);
}
int main()
{
    int a[] = {1, 2, 4, 2, 2, 7};
    cout << "First= " << First(a, 7, 0, 4) << " Last= " << Last(a, 7, 4);
    return 0;
}