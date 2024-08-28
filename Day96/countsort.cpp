#include <iostream>
#include <vector>
using namespace std;

vector<int> countSort(vector<int> arr, int n) {
    // Find the maximum element in the array
    int k = arr[0];
    for(int i = 0;i<n;i++){
        k = max(k, arr[i]);
    }

    vector<int> count(k+1, 0);
    for(int i = 0;i<n;i++){
        count[arr[i]]++;
    }

    for(int i = 1;i<=k;i++){
        count[i] += count[i-1];
    }

    vector<int> sorted(n);
    for(int i = n-1;i>=0;i--){
        sorted[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    return sorted;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> sorted = countSort(arr, n);

    for(int i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << " ";
    }
    return 0;
}
