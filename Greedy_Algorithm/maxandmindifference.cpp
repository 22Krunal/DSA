#include <bits/stdc++.h>

using namespace std;

int main()
{

    int a[] = {0, -3, 10, 12};
    sort(a, a + 4);
    int Min = 0, Max = 0;

    for (int i = 0; i < 4; i++)
        cout << a[i] << " ";

    cout << endl;

    for (int i = 0; i < 2; i++)
    {
        // min diff should be minimum that's why odd terms minus even term
        Min += abs(a[2 * i + 1] - a[2 * i]);
        // max diff should be maximum that's why max terms minus min term
        Max += abs(a[3 - i] - a[i]);
    }


    cout << Max << " " << Min << endl;
    return 0;
}