#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Given a sorted array containing only 0s and 1s, find the transition point, i.e., 
// the first index where 1 was observed, and before that, only 0 was observed.

int transition(vector<int>& arr, int n){
    int count = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] == 1){
            return count;
        }
        count++;
    }
    return -1;
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

    int trans = transition(arr, n);
    
    cout<<trans<<endl;

    return 0;
}
