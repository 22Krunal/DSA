#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;

    priority_queue<int ,vector<int>>maxheap;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        maxheap.push(x);
    }
    int sum=0,prev=0;
    while (!maxheap.empty())
    {
        prev=maxheap.top();
        sum+=prev;
        maxheap.pop();
        if(sum>=k)
        {
            cout<<"size :"<<n-maxheap.size()<<endl;
            break;
        }
    }
    return 0;

    
}