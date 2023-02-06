#include <bits/stdc++.h>

using namespace std;

void insertInHeap(int a[], int index, int value, int size)
{
    if (index >= size)
    {
        cout << "Heap is full already!!!!" << endl;
        return;
    }
    a[index] = value;
    while (index > 0)
    {
        int parent = ceil(index / 2);
        if (a[parent] < a[index])
        {
            swap(a[parent], a[index]);
            index = parent;
        }
        else
            return;
    }
}
void deleteInHeap(int a[], int n, int size)
{

    if (n < 0)
    {
        cout << "Heap is already empty!!" << endl;
        return;
    }
    // storing last element in array to make sorting easy
    swap(a[0], a[n]);
    int i = 0;
    while (i < n)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int larger = 0;
        if (left < n && right < n)
            larger = a[left] > a[right] ? left : right;
        else
            larger = left;
        if (larger < n && a[i] < a[larger])
        {
            swap(a[i], a[larger]);
            i = larger;
        }
        else
            return;
    }
}
// my function to do heapify
void Heapify(int a[], int index, int size)
{
    if (index == 0)
    {
        cout << "Heap is empty!" << endl;
        return;
    }
    // leaf nodes start from n/2+1 index though leaf nodes are alway a heap
    index = index / 2;
    while (index >= 0)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int larger = 0;
        if (left < size && right < size)
            larger = a[left] > a[right] ? left : right;
        else
            larger = a[left];
        if (larger < size && a[index] < a[larger])
        {
            swap(a[larger], a[index]);
            // to cheack for the tree thah is below that
            index += 2;
        }
        // cout<<"k ";
        index--;
    }
}
// for this fuction we have to make another fuction that is build heap
void heapify(int a[], int index, int size)
{
    if (index < 0)
        return;
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < size && a[largest] < a[left])
    {

        largest = left;
    }
    if (right < size && a[largest] < a[right])
    {
        largest = right;
    }
    if (largest != index)
    {
        swap(a[largest], a[index]);
        heapify(a, largest, size);
    }
}
void buildheap(int a[], int size)
{
    for (int i = (size - 1) / 2; i >= 0; i--)
        heapify(a, i, size);
}
void Heapsort(int a[], int size)
{
    // to create a heap : O(n)
    Heapify(a, size - 1, size);

    // Deleting element one by one and storing at end :nO(logn)
    for (int i = 0; i < size; i++)
        deleteInHeap(a, size - 1 - i, size);

    // printing sorted array
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";

    cout << endl;
}
//heap sort function 
void heapsort(int a[],int size){
    //to build heap
    buildheap(a,size);

    // Deleting element one by one and storing at end :nO(logn)
    for (int i = 0; i < size; i++)
        deleteInHeap(a, size - 1 - i, size);

    // printing sorted array
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";

    cout << endl;

}
int main()
{
    int a[5] = {10, 20, 15, 30, 40};

    for (int i = 0; i < 5; i++)
        insertInHeap(a, i, a[i], 5);

    // sorting elements
    for (int i = 4; i >= 0; i--)
        deleteInHeap(a, i, 5);
    // print sorted array
    for (auto i : a)
        cout << i << " ";

    cout << endl;

    // To check heapify function
    int b[] = {10, 20, 15, 30, 40};
    // Heapify(b, 4, 5);
    buildheap(b, 5);

    // sorting elements
    for (int i = 4; i >= 0; i--)
        deleteInHeap(b, i, 5);

    for (auto it : b)
        cout << it << " ";

    cout << endl;

    int c[] = {10, 20, 20, 30, 40};

    // cout << "My heap sort function ::";
    // Heapsort(c, 5);
    
    cout<<"Heap sort function ::";
    heapsort(c,5);
    return 0;
}