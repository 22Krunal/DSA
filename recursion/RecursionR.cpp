#include<bits/stdc++.h>


using namespace std;

long long int MOD = 1e9+7;
int sum(int n){
    if(n == 0){
        return n;
    }

    return n + sum(n-1);
}

long long int factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return (n*factorial(n-1))%MOD;
}
// m^n;
long long int pow(int m, int n){
    if(n == 1){
        return m;
    }
    return (m*pow(m,n-1))%MOD;
}
// optimized
long long int power(int m,int n){
    if(n == 0){
        return 1;
    }
    if(n%2 == 0){
        return (power(m*m,n/2))%MOD;
    }
    return (m*power(m*m,(n-1)/2))%MOD;
}
double e(int x, int n){
    static int p = 1, f = 1;
    int res;
    if(n == 0){
        return 1;
    }
    res = e(x,n-1);
    p = p*x;
    f = f*n;

    return res + p/f;
}
int fib(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}
int c(int n, int r){
    if(r == 1){
        return n;
    }
    return c(n-1,r-1)*n/r;
}
//Tower of hanoi
static int x = 0;
void TOH(int n, int a,int b, int c){
    if(n ==  0){
        return ;
    }
    TOH(n-1,a,c,b);
    x++;
    // cout << "Move disk from " << a << " to " << c << " using " << b << endl;
    TOH(n-1,b,a,c);
}
int main(){
    
    int n;cin >> n;
    // cout << "Sum of first n Natural numbers: " << sum(n) << endl;
    // cout << "Factorial of n : " << factorial(n) << endl;
    // int m;cin >> m;
    // cout << "M^n :" << power(m,n) << endl;
    // cout << "Fibnacci Number : " << fib(n) << endl;
    // cout << "nCr : " << c(m,n) << endl;
    TOH(16,1,2,3);
    cout << x << endl;
    return 0;
}