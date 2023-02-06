#include<bits/stdc++.h>


using namespace std;

void radixSort(vector<pair<pair<int,int>,int>> & a){
    
    int n = a.size();

    {
    // for second element of the pair
        vector<int> freq(n,0);
        for(auto it : a){
            freq[it.first.second]++;        //counting size of buckets
        }
        vector<pair<pair<int,int>,int> > aNew(n);
        
        //to give right position
        vector < int > pos(n);
        pos[0] = 0;
        for(int i=1; i<n; i++){
            pos[i] = pos[i-1] + freq[i-1];     // remember first position to give 
        }
        
        // allocating positions
        for(auto it : a){              
            int i = it.first.second;
            aNew[pos[i]] = it;
            pos[i]++;
        }
        //copy vector 
        a = aNew;
    }
    {
    //do same for the first element of the pair
        vector<int> freq(n,0);
        for(auto it : a){
            freq[it.first.first]++;
        }
        vector<pair<pair<int,int>,int> > aNew(n);
        //to give right position
        vector < int > pos(n);
        pos[0] = 0;
        for(int i=1; i<n; i++){
            pos[i] = pos[i-1] + freq[i-1];
        }

        for(auto it : a){
            int i = it.first.first;
            aNew[pos[i]] = it;
            pos[i]++;
        }

        a = aNew;
    }

}
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
        radixSort(a);
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