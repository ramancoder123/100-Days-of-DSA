#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int product(vector<int> arr, int n){
    sort(arr.begin(), arr.end());

    long result = 0;

    for(int i = 0;i<n;i++){
        result += (long)arr[i] * i;
        result %= 1000000007;
    }
    return (int)result;
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
    cout<<product(arr, n);

    return 0;
}