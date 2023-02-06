// optimized version
//google,amazon,facebook,visa
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], sum = 0;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> sum;
    int current = 0, j = 0;
    while (j < n && current <= sum)
    {
        current += a[j];
        j++;
        // cout<<current;
    }
    j--;
    if (current - a[j] == sum)
        cout << "1"
             << " " << j << endl;
    else
    {
        for (int i = 1; i < n; i++)
        {
            j = i;
            current = 0;
            while (j < n && current <= sum)
            {
                current += a[j];
                j++;
            }
            j--;
            if (current - a[j] == sum)
            {
                cout << i + 1 << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "";
    return 0;
}