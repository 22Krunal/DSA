#include<bits/stdc++.h>


using namespace std;


int main(){

    string str; cin >> str;


    str += "$";                    // for empty string 
    int len = str.length();
    vector < int > p(len), c(len); // p - prefix array ,c - class array 
    
    // k = 0 
    vector < pair < char , int > > a(len);   // char and its position

    for(int i=0; i<len; i++){
        a[i] = {str[i],i}; 
    }
    //sort it in lexilogical order
    sort(a.begin(), a.end());

    // make prefix array for k == 0
    for(int i= 0 ; i<len; i++){
        p[i] = a[i].second;
    }

    // make class array for k == 0
    c[p[0]] = 0;
    for(int i=1; i<len; i++){
        if(a[i].first == a[i-1].first){
            c[p[i]] = c[p[i-1]];
        }
        else{
            c[p[i]] = 1 + c[p[i-1]];
        }
    }
    
    // for rest of the k
    //  till 2^k is less than len of the string 
    int k = 0;
    while((1 << k) < len){

        // k -> k+1 ;
        vector < pair<pair<int, int >, int >> a(len);  // pair - {{class of left string , class of right string}, its position}
 
        for(int i=0; i<len; i++){
            a[i] =  { { c[i], c[( i + (1 << k))%len] }, i}; // classes and its position  
        } 
        
        // sort it in a lexilogical order 
        sort(a.begin(), a.end());
        // now update values in the prefix and class array
        
        for(int i=0; i<len; i++){
            p[i] = a[i].second;
        }

        c[p[0]] = 0;

        for(int i=1; i<len; i++){
            if(a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]];
            }
            else{
                c[p[i]] = 1 + c[p[i-1]];
            }
        }

        k++;
    }

    // print the prefix array and substring 

    for(int i=0; i<len; i++){
        cout << p[i] << " " << str.substr(p[i], len-p[i]) << endl;
    }
    return 0;
}