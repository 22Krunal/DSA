#include<bits/stdc++.h>
using namespace std;
bool isOperator(char c){
    if(c=='+'||c=='-'||c=='/'||c=='*')
    return true;
    return false;
}
int redundant_parenthisis(string s){
    int ans=0;
    stack <char> st;
    int n=s.length();
    for(int i=0;i<n;i++){
        if(isOperator(s[i]))
        st.push(s[i]);
        else if(s[i]=='(')
        st.push(s[i]);
        else if(s[i]==')'){
            if(st.top()=='(')
            ans++;
            else{
            while (!st.empty()&&st.top()!='(')
                st.pop();     
            }
            st.pop();
        }
    }
    return ans;
}
int main(){
        string eq;
        cin>>eq;
        cout<<redundant_parenthisis(eq);
    return 0;
}