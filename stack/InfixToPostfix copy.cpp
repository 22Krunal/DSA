/* if '(' then push
   if ')' then pop till '('
   if  oprator then check the precidence and push if top has lower precidence else pop till low precidence
   else add in result string
*/
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
void ToPostfix(string s)
{
    stack<char> operators;
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')') // if closing bracket pop till open bracket
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
        { // if oprator than pop till precidence is lower than current one
            while (!operators.empty() && (Precidence(s[i]) <= Precidence(operators.top())))
            {
                result += operators.top();
                operators.pop();
            }
            operators.push(s[i]); // than push
        }
        else if (s[i] == '(')
            operators.push(s[i]);
        else // oprends
            result += s[i];
    }
    while (!operators.empty())
    {
        result += operators.top();
        operators.pop();
    }
    cout << result << endl;
}


int main()
{
    string s;
    cout << "Enter the Eqution: ";
    cin >> s;
    ToPostfix(s);
    return 0;
}
