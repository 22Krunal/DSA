#include<bits/stdc++.h>


using namespace std;

int numberofSubsequence(string str){

    int e = 1;  // count of all strings till curr element 
    int a = 0, ab =0 , abc = 0; // count of 'a','ab','abc' till curr element

    for(int i=0; i<str.length(); i++){

        if(str[i] == 'a'){
            a += e;
        }
        else if(str[i] == 'b'){
            ab += a;
        }
        else if(str[i] == 'c'){
            abc += ab;
        }
        else if(str[i] == '?'){
            abc = 3*abc + ab;
            ab = 3*ab + a;
            a = 3*a + e;
        }
    }
    return abc;
}

int main(){

    string str; cin >> str;
    
    cout << numberofSubsequence(str);
    return 0;
}