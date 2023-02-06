#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    int a[n][n] = {{1, 2, 3, 4, 25}, {5, 6, 7, 8, 24}, {9, 10, 11, 12, 23}, {13, 14, 15, 16, 22}, {17, 18, 19, 20, 21}};
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n - i; j++) //to move left to right 
            cout << a[i][j] << " ";
        for (int j = (i + 1); j < n - i; j++) //to move up to down 
            cout << a[j][(n - i - 1)] << " ";
        for (int j = (n - i - 2); j >= (i); j--) //to move right to left
            cout << a[(n - i - 1)][j] << " "; 
        for (int j = (n - i - 2); j > (i); j--)  //to move down to up
            cout << a[j][i] << " ";
    }
    cout << "";
    return 0;
}