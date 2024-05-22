#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int median(vector<vector<int> >& arr, int n, int m){
    int mi = INT_MAX;
    int mx = INT_MIN;

    for(int i = 0;i<n;i++){
        mi = min(mx, arr[i][0]);
        mx = max(mx, arr[i][m-1]);
    }

    int ans;
    
    while(mi <= mx){
        int mid = mi + (mx-mi)/2;
        int freq = 0;

        for(int i =0;i<n;i++){
            freq += upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();
        }

        if(freq >= (n * m + 1)/2){
            ans = mid;
            mx = mid - 1;
        }
        else{
            mi = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<< "Enter rows number : ";
    cin>>n;

    int m;
    cout<< "Enter columns number : ";
    cin>>m;

    vector<vector<int> > arr(n, vector<int> (m, 0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    cout<< "Median : "<<median(arr, n, m);

    return 0;
}