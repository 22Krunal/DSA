// first negative in every subarray of size k
#include<bits/stdc++.h>


using namespace std;

vector<int> firstNegative(int arr[], int n, int k){
    vector<int>res;
    queue<int> q;
    if(k > n){ // window size is bigger than size of array
        return res;
    }

    for(int i=0; i<k; i++){ // creating the window
        if(arr[i] < 0 ){
            q.push(i);
        }
    }
    int i = 0 , j = k;
    while (j <= n)
    {
        if(q.empty()){
            res.push_back(0);
        }
        else if(q.front() < i){
            while(!q.empty() && q.front() < i){
                q.pop();
            }
            if(q.empty()){
                res.push_back(0);
            }
            else{
                res.push_back(arr[q.front()]);
            }
        }
        else{
            res.push_back(arr[q.front()]);
        }
        if(arr[j] < 0){
            q.push(j);
        }
        i++;
        j++;
    }
    
    return res;
}
int main(){
    int arr[] = {1,2,-5,6,-1,-3,-4,9};
    int n = 8;
    int k = 2;
    vector<int> ans = firstNegative(arr,n,k);
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}