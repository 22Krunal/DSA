#include <bits/stdc++.h>

using namespace std;

int main()
{

    int coin[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int x;
    cin >> x;

    int i = 0;
    // till we make x from change
    while (x > 0)
    {

        // count of particular coin to be needed to make remaining x
        if (x >= coin[i])
        {
            int temp = x / coin[i];
            x -= temp * coin[i];
            cout << coin[i] << "->" << temp << endl;
        }
        i++;
    }
    return 0;
}