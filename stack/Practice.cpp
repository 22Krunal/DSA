#include<bits/stdc++.h>


using namespace std;


// stock span problem
vector<int> stockSpan(int arr[], int n){
    vector<int>res;
    stack<pair<int,int>> st;
    st.push({arr[0],1});
    res.push_back(1);
    for(int i=1; i<n; i++){
     
        int days = 1;
        if(arr[i] >= st.top().first){
            while(!st.empty() && arr[i] >= st.top().first ){
                days += st.top().second;
                st.pop();
            }
            st.push({arr[i],days});
        }
        else{
            st.push({arr[i],days});
        }
        res.push_back(days);
    }
    return res;
}
//Infix to postfix
// check if character is operator or not 
bool isOperator(char c){
    if(c == '*' || c == '/' || c == '+' || c == '-' || c == '^'){
        return true;
    }
    return false;
}
//
//helps to decide precedens of the operators
int predicens(char c){
    if(c == '('){
        return 0;
    }
    if(c == '+' || c == '-'){
        return 1;
    }
    if(c == '*' || c == '/'){
        return 2;
    }
    if(c == '^'){
        return 3;
    }
}
string InfixToPostfix (string s){
    int n = s.length();
    stack<char> st;
    string res = "";
    for(int i=0; i<n; i++){
        if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] ==  ')'){

            while(!st.empty() && st.top() != '(' ){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else if(isOperator(s[i])){
            // operators
            while(!st.empty() && predicens(st.top()) >= predicens(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else{ 
            // varibles 
            res += s[i];
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}
// infix to prefix 
string InfixToPrefix(string s){
    int n = s.length();
    reverse(s.begin(),s.end());
    for(int i=0; i<n; i++){
        if(s[i] == ')'){
            s[i] = '(';
        }
        else if(s[i] == '('){
            s[i] = ')';
        }
    }
    string res = InfixToPostfix(s);
    reverse(res.begin(), res.end());
    return res;
}
int main(){
     
    // stock span
    // int arr[] = {100,80,60,70,60,75,85};
    // int n = 7;
    // vector <int> res = stockSpan(arr,n);
    // for(auto it : res){
    //     cout << it << " ";
    // }

    // infix to postfix 
    string s = "A+((B-C)+D)";
    cout << InfixToPostfix(s) << endl;
    cout << InfixToPrefix(s) << endl;
    return 0;
}