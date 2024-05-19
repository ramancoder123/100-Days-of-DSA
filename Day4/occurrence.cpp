#include <iostream>
#include <vector>
using namespace std;

// Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.

int occurrence(vector<int>& arr, int n, int x){
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == x){
            cnt++;
        }
    }
    return cnt;
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

    int x;
    cout<< "Enter x value : ";
    cin>>x;

    cout<< "Occurrence : "<<occurrence(arr, n, x);

    return 0;
}