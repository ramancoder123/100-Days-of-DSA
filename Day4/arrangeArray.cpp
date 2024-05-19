#include <iostream>
#include <vector>

using namespace std;

// You are given an array of size N. Rearrange the given array in-place 
// such that all the negative numbers occur before all non-negative numbers.
// (Maintain the order of all -ve and non-negative numbers as given in the original array).


vector<int> arrangeArray(vector<int>& arr, int n){
    vector<int> pos;
    vector<int> neg;

    for(int i = 0;i<n;i++){
        if(arr[i] >= 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }

    int a = pos.size();
    int b = neg.size();

    int temp = 0;
    for(int i = 0;i<b;i++){
        arr[temp] = neg[i];
        temp++;
    }
    for(int i = 0;i < a;i++){
        arr[temp] = pos[i];
        temp++;
    }
    return arr;
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

    cout<< "Arranged array : ";
    vector<int> ans = arrangeArray(arr, n);
    for(int i = 0;i<n;i++){
        cout<<ans[i]<< " ";
    }
}