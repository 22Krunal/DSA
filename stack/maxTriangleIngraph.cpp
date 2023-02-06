#include<bits/stdc++.h>
using namespace std;

int getmaxArea(vector <int> a){
    a.push_back(0);
    stack <int > b;
    int MAX=INT_MIN;
    b.push(a[0]);
    for(int i=0;i<a.size();i++){
        if(!b.empty()&&a[i]>b.top()){ //push height until top is less than current element
            b.push(a[i]);
        }
        else{
            int l=1;
            while(!b.empty()&&a[i]<b.top()){ //if not than than count area till that element
               int area=b.top()*l;
               l++;
               MAX=max(MAX,area);
               b.pop();
            }
            b.push(a[i]);
        }
    }
  return MAX;
}
int main(){
    vector <int >a={2,1,5,6,7,2,3,16,17};
    cout<<getmaxArea(a);
}
