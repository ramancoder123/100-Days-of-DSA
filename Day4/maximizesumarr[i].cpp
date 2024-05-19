#include <iostream>
#include <vector>

using namespace std;

int product(vector<int> arr, int n){
    long result = 0;

    for(int i = 0;i<n;i++){
        result += (long)arr[i] * i;
        result %= 1000000007;
    }
    return result;
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