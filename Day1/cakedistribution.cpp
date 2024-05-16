#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(int mid, vector<int> &arr, int k){
    int person = 0;
    int sum = 0;

    for(int i = 0;i<arr.size();i++){
        sum += arr[i];
        if(sum >= mid){
            person++;
            sum = 0;
        }
    }
    return person >= k+1;
}

int cakeDistribute(vector<int>& sweetness, int k){
    int high = 0;
    int low = INT_MAX;
    int mid;

    for(int i = 0;i<sweetness.size();i++){
        low = min(sweetness[i], low);
        high += sweetness[i];
    }

    int ans = 0;

    while(low <= high){
        mid = (low + high)/2;

        if(isPossible(mid, sweetness, k)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {6, 3, 2, 8, 7, 5};
    int d = 2;

    cout<<cakeDistribute(arr, d);
}