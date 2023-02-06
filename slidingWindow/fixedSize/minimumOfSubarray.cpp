//print minimum of all subarray size k

#include<bits/stdc++.h>


using namespace std;

vector<int> minimumOfSubarray(int arr[], int n, int k){
    vector<int> res;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    for(int i=0; i<k; i++){
        pq.push({arr[i],i});
    }
    res.push_back(pq.top().first);

    int i = 0, j = k;

    while(j < n){
        if(pq.top().second <= i){
            while(!pq.empty() && pq.top().second <= i){
                pq.pop();
            }
        }
        pq.push({arr[j],j});
        res.push_back(pq.top().first);
        i++;
        j++;
    }
    return res;
}

int main(){
    int n = 8;
    int arr[] = {1,-4,5,-2,-5,78,-28,8};
    int k = 2;

    vector<int> ans = minimumOfSubarray(arr,n,k);

    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}