#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// You are given an array arr[] of N integers. 
// The task is to find the smallest positive number missing from the array.

// Note: Positive number starts from 1.

int smallestPositiveMissing(int arr[], int n){
    sort(arr, arr + n);

    int count = 1;
    for(int i = 0;i<n;i++){
        if(arr[i] == count){
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cout<< "Enter array size : ";
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int missing = smallestPositiveMissing(arr, n);
    cout<< missing<<endl;

    return 0;
}