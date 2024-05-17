#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Given a sorted array arr containing n elements with possibly some duplicate, 
// the task is to find the first and last occurrences of an element x in the given array.
// Note: If the number x is not found in the array then return both the indices as -1.

vector<int> firstAndLast(vector<int>& arr, int n, int x){
    vector<int> ans(2, -1);
    int count = 0;

    for(int i = 0;i<n;i++){
        if(arr[i] == x && count == 0){
            count++;
            ans[0] = i;
        }

        if(arr[i] == x && count >= 1){
            count++;
            ans[1] = i;
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

    int x;
    cout<< "Enter element whose occurrence is to be checked : ";
    cin>>x;

    vector<int> ans = firstAndLast(arr, n, x);

    cout<< "First occurrence : "<<ans[0]<<endl;
    cout<< "Last occurrence : "<< ans[1]<<endl;

    return 0;
}