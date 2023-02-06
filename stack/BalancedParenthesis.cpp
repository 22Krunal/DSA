#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    stack<char> paren;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            paren.push(s[i]);
        else if (s[i] == ')')
        {
            if (!paren.empty() && paren.top() == '(')
                paren.pop();
            else
                return false;
        }
        else if (s[i] == '}')
        {
            if (!paren.empty() && paren.top() == '{')
                paren.pop();
            else
                return false;
        }
        else if (s[i] == ']')
        {
            if (!paren.empty() && paren.top() == '[')
                paren.pop();
            else
                return false;
        }
    }
    if (!paren.empty())
        return false;
    return true;
}
int main()
{
    string s = "[{()}}";
    if (isValid(s))
        cout << "Valid string";
    else
        cout << "InValid string";
    return 0;
}