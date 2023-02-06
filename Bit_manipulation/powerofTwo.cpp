#include<bits/stdc++.h>


using namespace std;

//my approch
bool isPowerofTwo(int n){
    
    while(n > 0 ){
        n = n >> 1;

        if((n & 1) && !(n >> 1) ){
            
            return true;
        }
        else if((n&1)){
            return false;
        }
    }
    // return false;
}

bool isPow(int n){
    
    // 1000 (8) & 0111(7) its like they are 1's complement of each other
    //  return !( n & n-1 ); 
    //  too avoid case of zero we take

    return (n && !( n & n-1));
}
int main(){
    
    int n; cin >> n;

    cout << isPowerofTwo(n) << endl;
    cout << isPow(n) << endl;
    return 0;
}