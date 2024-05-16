#include <iostream>
using namespace std;

int secondSmallest(int arr[], int n){
    if(n < 2){
        return -1;
    }

    int first = INT_MIN;
    int second = INT_MIN;
    
    for(int i = 0;i<n;i++){
        if(arr[i] > first){
            second = first;
            first = arr[i];
        }
        else if(arr[i] > second && arr[i] != first){
            second = arr[i];
        }
    }

    if(second == INT_MIN){
        return -1;
    }
    return second;
}

int main(){
    int n;
    cout<< "Enter size : ";
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    cout<< secondSmallest(arr, n)<<endl;

    return 0;
}