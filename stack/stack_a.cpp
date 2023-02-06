#include<bits/stdc++.h>
using namespace std;
int size=100;
int *arr;
int top=-1;
bool isFull(){
    if(top==size-1)
    return true;
    else 
    return false;
}
bool isEmpty(){
    if(top==-1)
    return true;
    else 
    return false;
}
void Push(int a[],int data){
    if(isFull())
    {
        cout<<"Stack is Full!!!"<<endl;
        return ;
    }
    top++;
    a[top]=data;
    return;
}
int Top(int a[]){
    if(isEmpty()){
        cout<<"Stack is Empty!!!"<<endl;
        return INT_MIN;
    }
    return a[top];
}
void Pop(int a[]){
    if(isEmpty()){
        cout<<"Stack is Empty!!!"<<endl;
        return ;
    }
    top--;
}
int main(){
     arr=(int*)malloc(size*sizeof(int));
     Push(arr,1);
     Push(arr,2);
     cout<<Top(arr)<<endl;

     Pop(arr);
     cout<<Top(arr)<<endl;

     Push(arr,3);
     cout<<Top(arr)<<endl;
     Push(arr,4);
     Pop(arr);
     Push(arr,5);
     cout<<Top(arr)<<endl;

    return 0;
}