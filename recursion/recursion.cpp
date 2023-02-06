#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int power(int p, int n)
{
    if (n == 0)
        return 1;
    return p * power(p, n - 1);
}
int main()
{
    int n, p;
    cin >> p >> n;
    cout << power(p, n);
    return 0;
}