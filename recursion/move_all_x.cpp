#include <bits/stdc++.h>
using namespace std;
string Move(string s, char x, int n, int index)
{
  if (n == s.length())
    return s;
  if (x == s[index])
  {
    s.erase(index, 1); // remove that index and append at end of the list
    s += x;
  }
  else
  {
    index++; // check next one
  }
  return Move(s, x, n + 1, index);
}
int main()
{
  string s = "xxxxxaaaxxbx";
  cout << Move(s, 'x', 0, 0) << endl;
  return 0;
}