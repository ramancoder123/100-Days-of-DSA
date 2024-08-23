//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&v){
	    vector<int> v1(v.begin(), v.end());
	    sort(v1.begin(), v1.end());
	    int ans=0;
	    
	    unordered_map<int, pair<int, bool>> m;
	    for(int i=0; i<v.size(); i++){
	        m[v[i]]= {v1[i], false};
	    }
	  
	    for(int i=0; i<v.size(); i++){
	        if(m[v[i]].first!=v[i] && m[v[i]].second==false){
	            m[v[i]].second=true;
	            int val= v[i];
	            int point= m[v[i]].first;
	            
	            while(val!=point){
	                ans++;
	                m[point].second= true;
	                point= m[point].first;
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends