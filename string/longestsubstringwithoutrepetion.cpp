#include<bits/stdc++.h>
using namespace std;
void substring(string s){
    int len=s.length();
    vector <int > dist(256,-1); //vector of size 256 with all -1 
    int start=-1,maxlen=0;
    for(int i=0;i<len;i++){
        if(dist[s[i]]==-1)
        dist[s[i]]=i;
        else{
            maxlen=maxlen>(i-start)?maxlen:(i-start);
            start=i;
            dist[s[i]]=i;

        }
    }
    cout<<maxlen<<endl;
}
int main(){
    string s="aabefjekwjewkejkedjfoeewrjwoefrj";
    substring(s);
    return 0;
}
