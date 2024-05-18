#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given an array arr[] of n non-negative integers. 
// The task is to find the maximum of j - i (i<=j) 
// subjected to the constraint of arr[i] <= arr[j].

int maxIndex(vector<int> &arr, int n){
    vector<int> left;
    vector<int> right(n);

    int maxi = INT_MIN;
    int mini = INT_MAX;

    for(int i = 0;i<n;i++){
        mini = min(arr[i], mini);
        left.push_back(maxi);
    }

    for(int i = 0;i<n;i++){
        maxi = max(arr[i], maxi);
        right[i] = maxi;
    }

    int i = 0, j = 0;
    int ans = 0;

    while(i < n && j < n){
        if(arr[i] <= arr[j]){
            ans = max(ans, j-i);
            j++;
        }
        else{
            i++;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<< "Enter size : ";
    cin>>n;

    vector<int> arr;
    for(int i = 0;i<n;i++){
        int d;
        cin>>d;
        arr.push_back(d);
    }

    cout<< "Max Index : "<<maxIndex(arr, n)<<endl;

    return 0;
}