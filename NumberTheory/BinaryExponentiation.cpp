#include<bits/stdc++.h>

using namespace std;
#define ll long long 
const ll MOD=1e9+7;
ll pow(ll a,ll n){
    a%=MOD;
    ll ans=1;

    while (n>0)
    {
        if(n&1){
            ans=(a*ans)%MOD;
        }

        a=(a*a)%MOD;
        n=n>>1;
    }
    
    return ans;

}
int main(){
    
    ll a,n;cin>>a>>n;

    cout<<pow(a,n)<<endl;

    return 0;
}