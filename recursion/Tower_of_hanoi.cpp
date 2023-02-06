#include <bits/stdc++.h>
using namespace std;
void TowerofHanoi(int n, char base, char help, char nbase)
{
    if (n == 0)
    {
        return;
    }
    TowerofHanoi(n - 1, base, nbase, help);
    cout << base << "->" << help << endl;

    TowerofHanoi(n - 1, nbase, help, base);
}
int main()
{
    int n;
    cout << "Enter the number of blocks:";
    cin >> n;
    TowerofHanoi(n, 'A', 'C', 'B');
    return 0;
}
