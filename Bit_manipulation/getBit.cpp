#include<bits/stdc++.h>


using namespace std;

int getBit(int n, int i){


    // return ( (n & (1 << i)) != 0);

   // my approch 
   return ((n >> i & 1));
}
int main(){

    int n,i;cin >> n >> i;
    
    // for(int j=1; j<i; j++){
        cout << getBit(n,i);
    // }
    return 0;
}