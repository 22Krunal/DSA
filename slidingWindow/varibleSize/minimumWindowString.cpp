#include<bits/stdc++.h>


using namespace std;


string minWindow(string s, string t) {
    int m = t.length();
    map<char,int>mp;
    for(int i=0; i<m; i++){
            mp[t[i]]++;
    }
    int count = mp.size();
    int i = 0, j = 0 , n = s.length();
    int st = 0 , e = 0;
    int mn = INT_MAX;
    while(j < n){
        if(mp.find(s[j])!=mp.end()){
            mp[s[j]] --;
            if(mp[s[j]] == 0){
                count --;
            }
                
        }
        if(count == 0){
          if(mn > j-i+1){
                  mn = j-i+1;
                  st = i;
                      e = j;
            }
        while(count == 0){
            if(mn > j-i+1){
                mn = j-i+1;
                st = i;
                e = j;
                }
            if(mp.find(s[i]) != mp.end()){
                mp[s[i]] ++;
                if(mp[s[i]] == 1){
                    count ++;
                }
            }
            i++;
        }
    }
    j++;
    }
        // cout << mn << endl;
        if(mn == INT_MAX){
        return "";
        }
    return s.substr(st,e-st+1);
}
int main(){
    cout << "Enter the strings";
    string s,t;cin >> s >> t;
    cout<<minWindow(s,t) << endl;
    return 0;
}