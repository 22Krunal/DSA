//longest substring with no repeating characters

#include<bits/stdc++.h>


using namespace std;

int withOutRepeation(string s){
    int n = s.length();


    map<char,int>mp;
    int dist = 0;
    int i = 0 , j = 0;
    int mx = 0;

    while(j < n ){
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]++;
            if(mp[s[j]] == 1){
                dist++;
            }
        }
        else{
            mp[s[j]] = 1;
            dist ++;
        }
        if(dist  == j-i+1){
            mx = max(mx,j-i+1);
        }
        else if (dist < j-i+1){
            while(dist < j-i+1){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    dist--;
                }
                i++;
            }
        }
        j++;
    }
    return mx;
}

int main(){
    string  s = "pwwtrkewjmnp";
    cout << withOutRepeation(s) << endl;
    return 0;
}