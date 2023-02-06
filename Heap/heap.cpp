#include <bits/stdc++.h>
using namespace std;

struct Heap
{
    int *array;
    int size;
    int capacity;
    int heap_type;
    Heap(int val, int type)
    {
        capacity = val;
        array = (int *)malloc(sizeof(int) * capacity);
        heap_type = type;
        size = 0;
    }
};

void createHeap(int *a, int i)
{
    int parent = ceil(i / 2);
    if (i == 0 || a[i - 1] <= a[parent - 1])
        return;
    else
    {
        swap(a[i - 1], a[parent - 1]);
        return createHeap(a, parent);
    }
}

void buildHeap(int data, Heap *h)
{
    if (h->capacity == h->size)
    {
        cout << "Heap is Full" << endl;
    }
    h->array[h->size] = data;
    h->size++;
    createHeap(h->array, h->size);
    return;
}
void adjust(Heap * h,int curr){
    if(h->size==0)return ;
    int left=2*curr-1;
    int right=2*curr;
    int parent=ceil(curr/2);
    if(curr>h->size)return ;
      if(h->array[curr-1]>=h->array[parent-1]){
        swap(h->array[curr-1],h->array[parent-1]);
        adjust(h,parent);
        adjust(h,curr);
      }
    else if(h->array[curr-1]<=max(h->array[left],h->array[right])){
        if(h->array[left]>h->array[right]){
            swap(h->array[curr-1],h->array[left]);
            adjust(h,left+1);
        }
        else{
            swap(h->array[curr-1],h->array[right]);
            adjust(h,right+1);
        }
    }
}
void Delete( Heap * h)
{
    if(h->size==0)return ;
    swap(h->array[0],h->array[h->size-1]);
    cout<<h->array[h->size-1];
    h->size--;
    adjust(h,0);
}
int main()
{

    struct Heap *h = new Heap(6, 1);
    buildHeap(10, h);
    buildHeap(20, h);
    buildHeap(15, h);
    buildHeap(30, h);
    buildHeap(40, h);
    for (int i = 0; i < h->size; i++)
    {
        cout << h->array[i] << " ";
    }
    cout << endl;
    Delete(h);
    int a[5] = {10, 20, 15, 30, 40};
    for (int i = 0; i < 5; i++)
    {

        createHeap(a, i + 1);
        // printing array after every insertion
        cout << "iteration ->" << i + 1 << " ";
        for (int j=0;j<=i;j++)
            cout << a[j]<< " ";

        cout << endl;
    }
    return 0;
}
