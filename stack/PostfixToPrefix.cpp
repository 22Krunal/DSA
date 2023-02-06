#include <bits/stdc++.h>

using namespace std;
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}
void PostToPrefix(string s)
{
    stack<string> Stack;
    for (int i = 0; i < s.length(); i++)
    {
        if (!isOperator(s[i]))
        {
            string temp;
            temp.push_back(s[i]);
            Stack.push(temp);
        }
        else
        {
            string a = Stack.top();
            Stack.pop();
            string b = Stack.top();
            Stack.pop();
            Stack.push(s[i] + b + a);
        }
    }
    while (!Stack.empty())
    {
        cout << Stack.top() << endl;
        Stack.pop();
    }
    return;
}
int main()
{
    string s;
    cout << "Enter the Postfix Expression: ";
    cin >> s;
    PostToPrefix(s);
    return 0;
}