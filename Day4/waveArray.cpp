#include <iostream>
#include <vector>

using namespace std;

// Find better job opportunities this summer via Job-A-Thon Hiring Challenge!

// banner
// Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array(In Place).
// In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....

// If there are multiple solutions, find the lexicographically smallest one.

// Note:The given array is sorted in ascending order, and you don't need to return anything to make changes in the original array itself.

void waveArray(vector<int>& arr, int n){
    int i = 0;
    int j = 1;
    int temp;

    while(i < n && j < n){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i += 2;
        j += 2;
    }
}

int main(){
    int n;
    cout<< "Enter size : ";
    cin>>n;

    vector<int> arr;
    for(int i =0;i<n;i++){
        int d;
        cin>>d;
        arr.push_back(d);
    }

    waveArray(arr, n);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<< " ";
    }

}