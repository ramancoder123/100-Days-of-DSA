#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given an array arr of size n and an integer X. 
// Find if there's a triplet in the array which sums up to the given integer X.

bool isTriplet(int arr[], int n, int X){
    sort(arr, arr + n);

    for(int i = 0;i<n-2;i++){
        int s = i + 1;
        int e = n - 1;
        int sum = X - arr[i];

        while(s < e){
            if(arr[s] + arr[e] == X){
                return true;
            }
            else if(arr[s] + arr[e] < X){
                s++;
            }
            else{
                e--;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cout<< "Enter array : ";
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int X;
    cout<< "Enter required sum : ";
    cin>>X;

    if(isTriplet(arr, n, X)){
        cout<< "1";
    }
    else{
        cout<< "0";
    }

    return 0;
}