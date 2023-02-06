#include<bits/stdc++.h>


using namespace std;


// my approch
int countofOnes(int n){
    
    int count = 0;
    while(n>0){
        
        if( n & 1){
            count ++;
        }
        n = n >> 1;
    }
    return count;
}
int countof1s(int n){

    int cnt = 0 ;
    while(n){

        // after this n become n-2;
        // just difference of one bit that is one in n and n-1
        n = n & n-1;
        cnt++;
    }
    return cnt;
}
int main(){

    int n; cin >> n;

    cout << countofOnes(n) << endl;
    cout << countof1s(n) << endl;
    return 0;
}