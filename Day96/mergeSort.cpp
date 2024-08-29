#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int s, int mid, int e) {
    int len1 = mid - s + 1;
    int len2 = e - mid;

    vector<int> first(len1);
    vector<int> second(len2);

    for(int i = 0; i < len1; i++) {
        first[i] = arr[s+i];
    }

    for(int i = 0; i < len2; i++) {
        second[i] = arr[mid+1+i];
    }

    int i = 0, j = 0, k = s;
    
    while(i < len1 && j < len2) {
        if(first[i] <= second[j]) {
            arr[k++] = first[i++];
        } else {
            arr[k++] = second[j++];
        }
    }

    while(i < len1) {
        arr[k++] = first[i++];
    }

    while(j < len2) {
        arr[k++] = second[j++];
    }
}

void mergeSort(vector<int> &arr, int s, int e) {
    if(s >= e) {
        return;
    }

    int mid = s+(e-s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, mid, e);
}

int main() {
    int n;
    cout << "Enter input size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int s = 0;
    int e = n - 1;

    mergeSort(arr, s, e);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
