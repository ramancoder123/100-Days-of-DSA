#include <iostream>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size;

        Heap(){
            size = 0;
            arr[0] = -1;
        } 

        void insert(int data){
            size = size + 1;
            int idx = size;
            arr[idx] = data;

            while(idx > 1){
                int parent = idx/2;

                if(arr[idx] > arr[parent]){
                    swap(arr[idx], arr[parent]);
                    idx = parent;
                }
                else{
                    return;
                }
            }
        }

        void display(){
            for(int i = 1;i<=size;i++){
                cout<<arr[i]<< " ";
            }
            cout<<endl;
        }

        void deleteRoot(){
            arr[1] = arr[size];
            size--;

            int i = 1;
            while(i < size){
                int leftIndex = 2 * i;
                int rightIndex = 2 * i + 1;

                if(leftIndex < size && arr[i] < arr[leftIndex]){
                    swap(arr[i], arr[leftIndex]);
                }
                else if(rightIndex < size && arr[i] < arr[rightIndex]){
                    swap(arr[i], arr[rightIndex]);
                }
                else{
                    return;
                }
            }
        }
};

int main(){
    int data;
    cout<< "Enter data for the heap : ";
    cin>>data;

    Heap h;
    h.insert(data);

    while(data != 1){
        cin>>data;
        if(data == -1){
            break;
        }
        h.insert(data);
    }
    h.display();

    h.deleteRoot();
    h.display();

    return 0;
}