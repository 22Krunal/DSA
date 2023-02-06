// longest substring with k uniq characters 
#include<bits/stdc++.h>


using namespace std;

int longestSubstringwithKuniqchar(string s,int k){
    int n = s.length();
    int dist = 0;
    map<char,int> mp;
    int i = 0, j = 0;
    
    int mx = 0;
    while(j < n){
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]++;
        }
        else{
            mp[s[j]] = 1;
            dist++;
        }
        if(dist == k){
            mx = max(mx,j-i+1);
        }
        else if (dist > k){
            while(i<n && dist > k){
                mp[s[i]] --;
                if(mp[s[i]] == 0){
                    dist --;
                }
                i++;
            }
        }
        j++;
    }
    return mx;
}
int main(){

    string s = "aabacbebebe";
    int k = 3;
    cout << longestSubstringwithKuniqchar(s,k);
    return 0;
}