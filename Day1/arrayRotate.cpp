#include <iostream>
using namespace std;

void rotate(int arr[], int n, int d){
    int temp[n];
    
    for(int i = 0;i<n;i++){
        temp[i] = arr[i];
    }

    for(int i = 0;i<n;i++){
        arr[i] = temp[(i+d)%n];
    }
}

int main(){
    int n;
    cout<< "Enter size : ";
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int d;
    cout<< "Enter number of positions ot be roatated : ";
    cin>>d;

    rotate(arr, n, d);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<< " ";
    }
}