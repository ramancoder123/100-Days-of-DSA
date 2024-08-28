#include <iostream>
#include <vector>
#include <algorithm> // For sort function
using namespace std;

// Function to perform Bucket Sort
void bucketSort(vector<float> &arr, int n) {
    // Create n empty buckets
    vector<vector<float>> buckets(n);

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index in the bucket
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<float> arr(n);
    cout << "Enter elements between 0 and 1: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform Bucket Sort
    bucketSort(arr, n);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
