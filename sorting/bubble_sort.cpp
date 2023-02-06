// repetedly swap adject element if they are in wrong order
// It is called bubble sort because in evry interation max element will pop out at last
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
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    // for(int i=0;i<n;i++)
    // cout<<a[i]<<" ";
    cout << "";
    return 0;
}