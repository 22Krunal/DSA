#include<bits/stdc++.h>


using namespace std;

#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define rep(i,a,b) for(int i=a; i<b; i++)
#define print(a) cout << a << endl
#define vi vector<int> 
#define vii vector<pair<int,int>> 
#define pii pair<int,int>
#define mii map <int,int> 
#define pvi(a) for(auto it : a){cout << it << " ";} 
#define pp(a) for(auto it : a){cout << it.first << " " << it.second << endl;}
#define ll long long int
ll MOD = 1e9 + 7;


void bubbleSort(int arr[],int n){

    rep(i,0,n){
        rep(j,0,n-i-1){
            if(arr[j] > arr[j+1]){
                swap(arr[j+1],arr[j]);
            }
        }
        
    }
}
void selectionSort(int arr[],int n){
    rep(i,0,n){
        rep(j,i+1, n){
            if(arr[i] > arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}
void inserctionSort(int arr[], int n){
    rep(i,1,n){
        int curr = arr[i];
        int j = i-1;
        while(curr < arr[j] && j >=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
}
int partitiing (int arr[],int l, int r){
    int pivot = arr[l];
    int i = l;
    int j = r;
   do{
    do{
        i++;
    }while(arr[i] <= pivot);

    do{
        j--;
    }while(arr[j] > pivot);

    if(i < j){
        swap(arr[i],arr[j]);
    }

   }while(i<j);

   swap(arr[l] , arr[j]);
   return j;
}
void quickSort(int arr[], int l,int r){
    if(l < r){
        int pi = partitiing(arr,l,r);

        quickSort(arr,l,pi);
        quickSort(arr,pi+1, r);
    }
}
void merge(int arr[],int l,int mid,int r){
    int i=l,j=mid+1,k=l;
    int *temp = (int*)malloc(sizeof(int)*100);

    while(i <= mid && j <= r){
        if(arr[i] < arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    for(; i<= mid; i++){
        temp[k++] = arr[i];
    }
    for(; j<=r; j++){
        temp[k++] = arr[j];
    }
    rep(i,l,r+1){
        arr[i] = temp[i];
    }
    free(temp);
}
void ImergeSort(int arr[],int n){
    int i,l,h,p,mid;
    for(p=2; p<=n; p=p*2){
        for(i=0; i+p-1<n; i=i+p){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(arr,l,mid,h);
        }
    }
    if(p/2 < n){
        merge(arr,0,((p/2)-1),n-1);
    }
}
void mergeSort(int arr[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;

        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}
//another approch
void countSort(int arr[],int n){
    int mx = INT_MIN;
    rep(i,0,n){
        if(mx < arr[i]){
            mx = arr[i];
        }
    }

    vector<int> temp(mx+1, 0);

    rep(i,0,n){
        temp[arr[i]]++;
    }

    int sum = 0;
    rep(i,0,mx+1){
        temp[i] += sum;
        sum = temp[i];
    }
    int *b =(int*)malloc(sizeof(int)*n);
    for(int i=n-1; i>=0; i--){
        temp[arr[i]]--;
        int idx = temp[arr[i]];
        b[idx] = arr[i];
    }
    rep(i,0,n){
        arr[i] = b[i];
    }
    free(b);
    // cout << endl;
}
void CountSort(int arr[],int n){
    int mx = INT_MIN;
    rep(i,0,n){
        if(mx < arr[i]){
            mx = arr[i];
        }
    }

    vector<int> freq(mx+1, 0);
    rep(i,0,n){
        freq[arr[i]]++;
    }
    
    int j = 0, k = 0;
    while(j < mx+1){
        if(freq[j] > 0){
            arr[k++] = j;
            freq[j]--; 
        }
        else{
            j++;
        }
    }

}
void shellSort(int arr[],int n){

    for(int gap = n/2; gap>=1; gap/=2){
        for(int i = gap; i<n; i++){
            int curr = arr[i];
            int j = i-gap;
            while(j >=0 && arr[j] > curr){
                arr[j+gap] = arr[j];
                j -= gap;
            }
            arr[j+gap] = curr;
        }
    }
}
struct Node{
    int data;
    struct Node*next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
void insert(Node*head,int data){
    Node*tmp = (Node*)malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = NULL;
    if(!head){
        head = tmp;
        return ;
    }
    Node*n = head;
    while(n->next){
        n = n->next;
    }
    n->next = tmp;
    return ;
}
int Delete(Node*head){
    int data = head->data;
    head = head->next;
    return data;
}
void binSort(int arr[],int n){
    int mx = INT_MIN;
    rep(i,0,n){
        if(arr[i] > mx){
            mx = arr[i];
        }
    }
    Node **Bins;
    Bins = new Node*[mx+1];
    rep(i,0,mx+1){
        Bins[i] = NULL;
    }

    rep(i,0,n){
        insert(Bins[arr[i]],arr[i]);
    }

    int i = 0,j = 0;
    while(i < mx+1){
        while(Bins[i]!=NULL){
            arr[j++] = Delete(Bins[i]);
        }
        i++;
    }
}
void radixSort(int arr[],int n){

}
void solve(){

    int n; cin >> n;
    int arr[n];

    rep(i,0,n){
        cin >> arr[i];
    }
    
    // bubbleSort(arr,n);
    // selectionSort(arr,n);
    // inserctionSort(arr,n);
    // quickSort(arr,0,n);
    // mergeSort(arr,0,n-1);
    // countSort(arr,n);
    // CountSort(arr,n);
    // shellSort(arr,n);
    binSort(arr,n);
    // cout <<  " Bubbel sort: "
    rep(i,0,n){
        cout << arr[i] << " ";
    }
    cout << endl;

}


int main(){

    int tt; cin >> tt;

    while(tt--){
        solve();
    }
    return 0;
}