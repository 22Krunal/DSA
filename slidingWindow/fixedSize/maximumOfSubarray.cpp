//print maximum of all subarray of size k
#include<bits/stdc++.h>


using namespace std;

vector<int> maximumOfSubarray(int arr[], int n, int k){
    vector<int> res;

    priority_queue<pair<int,int>> pq;
    for(int i=0; i<k; i++){
        pq.push({arr[i],i});
    }

    int i = 0 , j = k;

    while(j <= n){
        res.push_back(pq.top().first);
        if(pq.top().second <= i){
            while(!pq.empty() && pq.top().second <= i){
                pq.pop();
            }
        }
        pq.push({arr[j], j});
        i++;
        j++;
    }
    return res;
}
int main(){
    
    int n = 8;
    int arr[] = {1,-4,5,-2,-5,78,-28,8};
    int k = 2;
    vector<int> ans = maximumOfSubarray(arr,n,k);

    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}