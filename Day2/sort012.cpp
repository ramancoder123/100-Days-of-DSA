#include <iostream>
#include <vector>
using namespace std;

// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

int* sorting(int arr[], int n){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for(int i = 0;i<n;i++){
        if(arr[i] == 0){
            count0++;
        }
        else if(arr[i] == 1){
            count1++;
        }
        else{
            count2++;
        }
    }
    int temp = 0;
    for(int i = 0;i<count0;i++){
        arr[temp] = 0;
        temp++;
    }
    for(int i = 0;i<count1;i++){
        arr[temp] = 1;
        temp++;
    }
    for(int i = 0;i<count2;i++){
        arr[temp] = 2;
        temp++;
    }

    return arr;
}

int main(){
    int n;
    cout<< "Enter array size : ";
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int* ans = sorting(arr, n);

    for(int i = 0;i<n;i++){
        cout<<ans[i]<< " ";
    }
}