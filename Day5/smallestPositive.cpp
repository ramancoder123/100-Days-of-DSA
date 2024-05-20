#include <bits/stdc++.h>
using namespace std;

long long smallestpositive(vector<long long> array, int n)
    { 
        sort(array.begin(), array.end());
        long long result = 1;
        
        for(int i = 0;i<n && array[i] <= result;i++){
            result += array[i];
        }
        return result;
} 

int main(){
    int n;
    cout<< "Enter size : ";
    cin>>n;

    vector<long long> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    cout<<smallestpositive(arr, n);
}