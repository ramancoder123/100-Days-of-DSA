#include <iostream>
#include <algorithm>
using namespace std;

// Given an array arr[] and an integer k where k is smaller than the size of the array, 
// the task is to find the kth smallest element in the given array. 
// It is given that all array elements are distinct.

int kthsmallest(int arr[], int n, int k){
    sort(arr, arr + n);

    return arr[k - 1];
}

int main(){
    int n;
    cout<< "Enter array size : ";
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int k;
    cout<<"Enter k value : ";
    cin>>k;

    cout<<kthsmallest(arr, n, k);
}