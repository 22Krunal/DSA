#include<bits/stdc++.h>


using namespace std;

//Recursive Version
bool isScrambled(string str1, string str2){
    if(str1.length() != str2.length()){
        return false;
    }
    if(str1.compare(str2) == 0 || str1.length() <1 && str2.length() <1){
        return true;
    }
    
    int n = str1.length();

    for(int i=1; i<n; i++){
        
        // condition 1 || condition 2
        // condition 1 - string is not swapped
        // condition 2 - string is swapped
        if((isScrambled(str1.substr(0,i),str2.substr(0,i))&&isScrambled(str1.substr(i,n-i),str2.substr(i,n-i)))||
           (isScrambled(str1.substr(0,i),str2.substr(n-i,i))&&isScrambled(str1.substr(i,n-i),str2.substr(0,n-i)))){
               return true;
           }
    }

    return false;
}
//Memoized Version

unordered_map < string , bool > mp;

bool isSCRAMBLED(string str1, string str2){

    if(str1.length() != str2.length()){
        return false;
    }
    if(str1.compare(str2) == 0 || str1.length() <1 && str2.length() <1){
        return true;
    }
    string key = str1 + " " + str2;

    if(mp.find(key) != mp.end()){
        return mp[key];
    }

    int n = str1.length();

    for(int i=1; i<n; i++){

        if((isScrambled(str1.substr(0,i),str2.substr(0,i))&&isScrambled(str1.substr(i,n-i),str2.substr(i,n-i)))||
           (isScrambled(str1.substr(0,i),str2.substr(n-i,i))&&isScrambled(str1.substr(i,n-i),str2.substr(0,n-i)))){
               return mp[key] = true;
           }

        
    }
    return mp[key] = false;
}
int main(){

    string str1,str2; cin >> str1 >> str2 ;
    
    if(str1.length() != str2.length()){  
        cout << "String is not srambled" << endl;
        return 0;
    }
    if(str1.compare(str2) == 0 || isSCRAMBLED(str1,str2)){
        cout << "String is Scrambled" << endl;
    }
    else{
        cout << "String is not srambled" << endl;
        
    }
    return 0;
}