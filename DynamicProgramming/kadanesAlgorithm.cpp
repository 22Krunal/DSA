#include<bits/stdc++.h>


using namespace std;


int main(){

    int n; cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int curr = 0;  // current sum
    int mx = INT_MIN; // maximum sum 
    for(int i=0; i<n; i++){
        curr+= arr[i];
        if(curr < 0){
            curr = 0;
        }

        mx = max(curr, mx);
    }
    cout << mx << endl;
    return 0;
}