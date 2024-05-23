#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int isPair(int arr[], int n, int x){
    sort(arr, arr+n);
        
    int i =0, j = 1;
        
        while(i < n && j < n){
            int diff = arr[j] - arr[i];
            
            if(diff == x && i != j){
                return 1;
            }
            else if(diff < x){
                j++;
            }
            else{
                i++;
            }
        }
        return -1;
}

int main(){
    int n;
    cout<< "Enter size : ";
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int x;
    cout<< "Enter x value : ";
    cin>>x;

    cout<<isPair(arr, n, x)<<endl;
}