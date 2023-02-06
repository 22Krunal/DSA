// x >> i removes bit from RSB
// x << i appends zero from RSB
// indexing from RSB
#include<bits/stdc++.h>


using namespace std;

int getBit(int n , int i){
  // return the bit at ith index
    return (n >> i & 1); 
}
int setBit(int n, int i){
   // set bit 1 at ith index
    return (n | 1 << i);
}
int clearBit(int n, int i){
    //set bit 0 at ith index
    
    // 1's comlement of num (fillping the bits)
    int mask = ~(1 << i);

    return (n & mask);
}
int main(){
   
    int n,i; cin >> n >> i;

    // cout << getBit(n,i) << endl;
    // cout << setBit(n,i) << endl;
    cout << clearBit(n,i) << endl;

    return 0;
}