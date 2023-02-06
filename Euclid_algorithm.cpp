// this algo use to find gcd of two numbers
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    while (a != 0)
    {

        int x = abs(a - b);
        //    cout<<a<<"-"<<b<<"="<<x<<endl;
        a = b;
        b = x;
    }
    return b;
}
int GCD(int a, int b)
{
    int rem = a % b;
    while (rem != 0)
    {
        rem = a % b;
        a = b;
        b = rem;
        // cout<<a<<" "<<b<<endl;
    }
    return a;
}
int main()
{
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b) << " " << GCD(a, b);
    return 0;
}