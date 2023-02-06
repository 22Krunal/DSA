#include <bits/stdc++.h>
using namespace std;
void sieve_of_eratosthenes(int n)
{
    int a[n];
    for (int i = 0; i < n; i++) // unmarked all numbers in starting
        a[i] = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == 1)
        { // picking all the elements who is not divisable by previous one (prime)
            int x = i + 1;
            for (int j = x * x; j <= n; j++)
            {
                if (a[j - 1] == 1 && (j % x) == 0) // storing j th smallest prime factor at j-1 index
                    a[j - 1] = x;
            }
        }
    }

    while (a[n - 1] != 1)
    { // printing all prime factors
        cout << a[n - 1] << " ";
        n = n / a[n - 1];
    }
    cout << n << endl;
}
int main()
{
    int n;
    cout << "Enter the number:";
    cin >> n;
    sieve_of_eratosthenes(n);
    return 0;
}