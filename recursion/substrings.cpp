#include<bits/stdc++.h>

using namespace std;

void substring (string s,int n){
    if(n==1)
    return ;
    cout<<s<<endl;
    substring(s.substr(1),n-1);
    cout<<s<<endl;
    substring(s,n+1);
}

int main(){

    string s="abc";
    substring(s,s.length());
    return 0;
}