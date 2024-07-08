#include <iostream>
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
};

int main(){
    heap h;
    cout<< "Enter data : ";

    int data;
    cin>>data;

    h.insert(data);

    while(data != -1){
        cin>>data;
        if(data == -1){
            break;
        }
        h.insert(data);
    }

    h.print();
    return 0;
}