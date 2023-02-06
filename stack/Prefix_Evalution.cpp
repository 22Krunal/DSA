#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}
int answer(int a, int b, char c)
{
    if (c == '+')
        return a + b;
    if (c == '-')
        return a - b;
    if (c == '*')
        return a * b;
    if (c == '/')
        return a / b;
    if (c == '^')
        return pow(a, b);
}
int value(char c)
{
    return ((int)c - 48);
}
void PrefixEvalution(string s)
{
    stack<int> oprands;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (!isOperator(s[i]))
            oprands.push(value(s[i]));
        else
        {
            int a = oprands.top();
            oprands.pop();
            int b = oprands.top();
            oprands.pop();
            oprands.push(answer(a, b, s[i]));
        }
    }
    cout << oprands.top() << endl;
    oprands.pop();
    return;
}

int main()
{
    string s;
    cout << "Enter the Eqation:";
    cin >> s;
    PrefixEvalution(s);
    return 0;
}