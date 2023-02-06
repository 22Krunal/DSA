//  count all occurance of anagram of string in given string

#include<bits/stdc++.h>


using namespace std;

int countAnagram(string s, string t){
    int k = t.length();
    map<char,int> mp;

    for(int i=0; i<k; i++){  // frequncy map
        mp[t[i]] ++;
    }

    int dist = mp.size();  // count of distinct charcters in string

    for(int i=0; i<k; i++){
        if(mp.find(s[i]) != mp.end()){
            mp[s[i]] --;

            if(mp[s[i]] == 0){   // curr char is no more needed
                dist --;
            }

        }
    }

    int i = 0, j = k;
    int n = s.length();
    
    int cnt = 0;
    while(j <= n){
        if(dist == 0){
            cnt++;
        }
        if(mp.find(s[i]) != mp.end()){
            mp[s[i]] ++;
            if(mp[s[i]] == 1){
                dist ++;
            }
        }
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]] -- ;
            if(mp[s[j]] == 0){
                dist --;
            }
        }
        i++;
        j++;
    }

    return cnt;
}
int main(){
    string s = "forxxorfdofr";
    string t = "for";
    cout << countAnagram(s,t) << endl;
    return 0;
}