#include<bits/stdc++.h>

using namespace std;

void bruteforce_span( vector <int > a){

int n=a.size();
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=i;j>=0;j--){
            if(a[i]>=a[j])
            count++;
            else
            break;
        }
        cout<<count<<" ";
    }
    cout<< endl;
}
vector <int > span(vector <int > prices){
    vector <int> ans;
    stack <pair<int,int>> s;
    for(auto price : prices){
          int days=1;
          while(!s.empty()&& s.top().first <= price){
              days+=s.top().second;
              s.pop();
          }
          s.push({price,days});
          ans.push_back(days);
    }

    return ans;
}

int main(){
    vector <int > a={100,80,60,70,60,75,85};
    bruteforce_span(a);
    vector <int > res=span(a);
    for(auto i : res)
    cout<<i<<" ";
    cout<<endl;
    

    return 0;
}