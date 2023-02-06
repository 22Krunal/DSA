#include<bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

//ax+by=gcd(a,b);
//gcd(d,0)=d;
struct triplet{

    int x;
    int y;
    int gcd;
};

triplet  extendedEuclid(int a,int b){
      
      if(b==0){

          triplet ans;
          ans.x=1;
          ans.y=0;
          ans.gcd=a;
          return ans;
      }

      triplet smallAns =extendedEuclid(b,a%b);

      triplet ans;
      ans.gcd=smallAns.gcd;
      ans.x=smallAns.y;
      ans.y=smallAns.x-(a/b)*smallAns.y;

      return ans;
}

int main(){

    int a,b;cin>>a>>b;
     

    triplet ans=extendedEuclid(a,b);
    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl; 
    return 0;
}