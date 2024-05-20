//{ Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
private:
    int binarySearch(vector<int>& temp, int target){
        int s = 0;
        int e = temp.size()-1;
        
        while(s <= e){
            int mid = (s+e)/2;
            
            if(temp[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return s;
    }
public:	
	vector<int> constructLowerArray(int *arr, int n) {
	    vector<int> ans(n), temp(arr, arr + n);
	    sort(temp.begin(), temp.end());
	    
	    for(int i = 0;i<n;i++){
	        int idx = binarySearch(temp, arr[i]);
	        
	        ans[i] = idx;
	        temp.erase(temp.begin() + idx);
	    }
	    return ans;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.constructLowerArray(arr, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends