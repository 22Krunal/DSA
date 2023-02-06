#include <bits/stdc++.h>
using namespace std;
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}

int Precidence(char a)
{
    if (a == '+' || a == '-')
        return 1;
    if (a == '*' || a == '/')
        return 2;
    if (a == '^')
        return 3;
    else
        return -1;
}
void ToPrefix(string s)
{
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
            s[i] = '(';
        else if (s[i] == '(')
            s[i] = ')';
    }
    stack<char> operators;
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                result += operators.top();
                operators.pop();
            }
            if (!operators.empty())
                operators.pop();
        }
        else if (isOperator(s[i]))
        {
            while (!operators.empty() && (Precidence(s[i]) <= Precidence(operators.top())))
            {
                result += operators.top();
                operators.pop();
            }
            operators.push(s[i]);
        }
        else if (s[i] == '(')
            operators.push(s[i]);
        else
            result += s[i];
    }
    while (!operators.empty())
    {
        result += operators.top();
        operators.pop();
    }
    reverse(result.begin(), result.end());
    cout << result << endl;
}
int main()
{
    string s;
    cout << "Enter the Eqution: ";
    cin >> s;
    ToPrefix(s);
    return 0;
}

// e^(l+k/c*b)+a
// elkc/b*+^a+
// +a^+*b/ckle
