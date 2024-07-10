#include <iostream>
#include <queue>
using namespace std;

class heap{
    public:
        int arr[100];
        int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int data){
        size = size + 1;
        int idx = size;
        arr[idx] = data;

        while(idx > 1){
            int parent = idx/2;

            if(arr[parent] < arr[idx]){
                swap(arr[parent], arr[idx]);
                idx = parent;
            }
            else{
                return;
            }
        }
    }

    void print() {
        for(int i = 1;i <= size;i++){
            cout<<arr[i]<< " ";
        }
        cout<<endl;
    }

    void deletion(){
        if(size == 0){
            cout<< "Invalid"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        // take root node to its correct position
        int i = 1;
        while(i < size){
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        // step 1
        swap(arr[size], arr[1]);
        size--;


        heapify(arr, size, 1);

    }
}

int main(){
    int n;
    cout<< "Enter size of tree : ";
    cin>>n;

    int arr[n];
    arr[0] = -1;
    for(int i = 1;i<=n;i++){
        cin>>arr[i];
    }

    for(int i = n/2;i>0;i--){
        heapify(arr, n, i);
    }
    cout<<endl;

    heapSort(arr, n);
    for(int i = 1;i<=n;i++){
        cout<<arr[i]<< " ";
    }

    cout<< "\nUsing Priority Queue : "<<endl;
    priority_queue<int> pq;

    pq.push(1);
    pq.push(2);
    pq.push(5);
    pq.push(2);

    cout<< "Element at top : "<<pq.top()<<endl;
    pq.pop();
    cout<< "Element at top : "<<pq.top()<<endl;
    cout<< pq.size()<<endl;

    // min heap

    priority_queue<int, vector<int> > minheap;
    pq.push(1);
    pq.push(2);
    pq.push(5);
    pq.push(2);

    cout<< "Element at top : "<<pq.top()<<endl;
    pq.pop();
    cout<< "Element at top : "<<pq.top()<<endl;
    cout<< pq.size()<<endl;    
    return 0;
}