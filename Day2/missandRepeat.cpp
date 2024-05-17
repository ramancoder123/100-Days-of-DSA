#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given an unsorted array Arr of size N of positive integers. 
// One number 'A' from set {1, 2,....,N} is missing and one number 'B' occurs twice in array.
//  Find these two numbers.

vector<int> missandrepeat(vector<int> &arr, int n){
    vector<int> ans;

    for(int i = 0;i<n;i++){
        if(arr[abs(arr[i]) - 1] > 0){
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
        else{
            ans.push_back(abs(arr[i]));
        }
    }
        
    for(int i = 0;i<n;i++){
        if(arr[i] > 0){
            ans.push_back(i+1);
        }
    }
    return ans;
}

int main(){
    int n;
    cout<< "Enter array size : ";
    cin>>n;

    vector<int> arr;
    for(int i = 0;i<n;i++){
        int d;
        cin>>d;

        arr.push_back(d);
    }

    vector<int> ans = missandrepeat(arr, n);

    cout<< "Repeating element : "<<ans[0]<<endl;
    cout<< "Missing element : "<< ans[1]<<endl;

    return 0;
}