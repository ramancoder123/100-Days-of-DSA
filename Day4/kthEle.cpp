#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K.
//  The task is to find the element that would be at the kth position of the final sorted array.

int kthelement(vector<int>& arr1, vector<int> &arr2, int n, int m, int k){
    int i = 0, j = 0;

    while(i < n && j < m){
        if(k == 1){
            return min(arr1[i], arr2[j]);
        }

        int mid1 = min(n, i + k/2) - 1;
        int mid2 = min(m, j + k/2) - 1;

        if(arr1[mid1] <= arr2[mid2]){
            k = k - (mid1 - i + 1);
            i = mid1 + 1;
        }
        else{
            k = k - (mid2 - j + 1);
            j = mid2 + 1;
        }
    }
    if(i < n){
        return arr1[k + i - 1];
    }
    else{
        return arr2[k + j - 1];
    }
}

int main(){
    int n;
    cout<< "Enter size of first array : ";
    cin>>n;

    vector<int> arr1;
    for(int i = 0;i<n;i++){
        int d;
        cin>>d;

        arr1.push_back(d);
    }

    int m; 
    cout<< "Enter size of secodn array : ";
    cin>>m;

    vector<int> arr2;
    for(int i = 0;i<m;i++){
        int d;
        cin>>d;

        arr2.push_back(d);
    }

    int k;
    cout<< "Enter position : ";
    cin>>k;

    cout<<kthelement(arr1, arr2, n, m, k);
    

    return 0;
}