#include <iostream>
#include <vector>
using namespace std;

// A utility function to get the maximum value in the array
int getMax(vector<int> arr, int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        maxVal = max(maxVal, arr[i]);
    }
    return maxVal;
}

// A function to do counting sort of arr[] according to the digit represented by exp.
void countSort(vector<int> &arr, int n, int exp) {
    vector<int> output(n); // Output array to hold sorted values
    vector<int> count(10, 0); // Count array to store the count of occurrences of each digit (0-9)

    // Store the count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that it contains the actual position of this digit in the output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr now contains the sorted numbers according to the current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// The main function to sort the array using Radix Sort
void radixSort(vector<int> &arr, int n) {
    // Find the maximum number to know the number of digits
    int maxVal = getMax(arr, n);

    // Do counting sort for every digit. The exp is 10^i where i is the current digit number
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Perform Radix Sort
    radixSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
