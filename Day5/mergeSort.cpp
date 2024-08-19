#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int n, int e, int s, int mid){
    int len1 = mid - s + 1;
    int len2 = e - mid;

    vector<int> first(len1);
    vector<int> second(len2);
    
    int k = s;
    for(int i = 0;i<len1;i++){
        first[i] = arr[k++];
    }
        
    k = mid + 1;
    for(int i = 0;i<len2;i++){
        second[i] = arr[k++];
    }

    int i = 0;
    int j = 0;
        
    k = s;
    while(i < len1 && j < len2){
        if(first[i] < second[j]){
                arr[k++] = first[i++];
        }
        else{
            arr[k++] = second[j++];
        }
    }
        
    while(i < len1){
       arr[k++] = first[i++];
    }
    while(j < len2){
        arr[k++] = second[j++];
    }
}

void mergeSort(vector<int>& arr, int n, int s, int e){
    if(s >= e){
        return;
    }
    int mid = (s+e)/2;

    mergeSort(arr, n, s, mid);
    mergeSort(arr, n, mid + 1, e);
    merge(arr, n, e, s, mid);
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

    mergeSort(arr, n, 0, n-1);

    for(int i = 0;i<n;i++){
        cout<<arr[i]<< " ";
    }
}