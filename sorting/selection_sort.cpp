// In every iteration select the kth smallest at put it at front
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}