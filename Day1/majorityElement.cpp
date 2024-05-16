#include <iostream>
using namespace std;

int majority(int arr[], int n){
    int count = 0;
    int el = 0;

    for(int i = 0;i<n;i++){
        if(count == 0){
            el = arr[i];
        }
        if(el == arr[i]){
            count++;
        }
        else{
            count--;
        }
    }
    count = 0;

    for(int i = 0;i<n;i++){
        if(arr[i] == el){
            count++;
        }
    }

    if(count < n/2){
        return -1;
    }
    return el;
}

int main(){
    int n;
    cout<< "Enter array size : ";
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    cout<< majority(arr, n);

    return 0;
}