// incompelete 
#include <bits/stdc++.h>

using namespace std;
string remove_duplicate(string s)   //but this only removes consucative duplicate 
{
    if (s.length() == 0)
        return "";
    char ch = s[0];
    string ans = remove_duplicate(s.substr(1));
    if (ch == ans[0])
        return ans;
    return (ch + ans);
}
string duplicate(string s){  //trying two remove all the duplicates
    if(n==0)
    return "";
   for(int i=0;i<s.length();i++){

   }

    
}
int main()
{
    string s = "aabbbcccdde";
    cout << remove_duplicate(s);
    return 0;
}