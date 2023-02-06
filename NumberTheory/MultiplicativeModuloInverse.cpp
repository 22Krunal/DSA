#include<bits/stdc++.h>

using namespace std;

//a*b%m=1;
//a*b-1=m*q;
//a*b+m*Q=1;

struct triplet{
    int x;
    int y;
    int gcd;
};

triplet extendedEuclid(int a,int b){
    if(b==0){
        triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    triplet smallAns=extendedEuclid(b,a%b);
    triplet ans;
    ans.x=smallAns.y;
    ans.gcd=smallAns.gcd;
    ans.y=smallAns.x-(a/b)*smallAns.y;
    return ans;
}
int multiplicativeModuloInverse(int a,int m){

    triplet ans=extendedEuclid(a,m);
       
       if(ans.x<0)
       ans.x+=m;
       
    return ans.x;
}

int main(){
    int a,m;cin>>a>>m;

    cout<<"B: "<<multiplicativeModuloInverse(a,m)<<endl;
    return 0;

}