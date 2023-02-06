
#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin >> n;
   
   int flag =0;
   int a[n],b[n];
    for(int i=0; i<n; i++){
       cin >> a[i];      
    } 
     for(int i=0; i<n; i++){
       cin >> b[i];      
    } 
    int diff = a[0] - b[0] ;
    for(int i=0; i<n; i++){
        
        if( (b[i] > a[i] && b[i] != 0) || (b[i] == 0 && a[i] > diff) || (diff != a[i] - b[i]) ){
            
            cout << b[i] << " "<< a[i] <<endl;
            cout << "NO" <<endl;
            return ;   
        }

    }
    cout <<"YES" <<endl;

   return ;
}


int main()
{
    int t; cin >> t;
    
    while(t--){
        solve();
    }

    return 0;
}

// void solve(){
//     int n,k; cin >> n >> k;
    
//     string s; cin >> s;
      
//       int cnt = 0, mx =INT_MIN;
//     for(int i=0; i<n; i++){
//        if(s[i] != 'B'){
//            mx = max(mx,cnt);
//            cnt--;
//        }
//        else{
//        cnt++; 
//        }
//     }
    
    
//     // cout << 0 << endl;
// }