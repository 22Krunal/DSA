#include <bits/stdc++.h>
using namespace std;
bool threesome(vector<int> a, int target)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (a[i] + a[j] + a[k] == target)
                {
                    cout << a[i] << " " << a[j] << " " << a[k] << endl;
                    return true;
                }
    return false;
}
bool twopointer(vector<int> a, int target)
{
    sort(a.begin(), a.end());
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        int low = i+1, high = n - 1;
        while (low < high)
        {
            int sum = a[i] + a[low] + a[high];
            if (sum > target)
                high--;
            else if (sum < target)
                low++;
            else
            {
                cout << a[i] << " " << a[low] << " " << a[high] << endl;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    vector<int> a = {12, 3, 5, 1, 6, 7, 9};
    threesome(a, 2);
    twopointer(a, 2);
    return 0;
}