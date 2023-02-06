#include <bits/stdc++.h>
using namespace std;
void reverse(string s)
{
    stack<string> san;
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i] != ' ' && i != s.length())
        {
            word += s[i];
            i++;
        }
        san.push(word);
    }
    while (!san.empty())
    {
        cout << san.top() << " ";
        san.pop();
    }
    cout << endl;
    return;
}

int main()
{
    string s = "hello my name is krunal";
    reverse(s);
    return 0;
}