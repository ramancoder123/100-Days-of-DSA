//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int cnt=0,maxi=0,n=s.size();
        map<int,int> mp;
        int l=0,r=0;
        while(r<n){
            mp[s[r]]++;
            if(mp[s[r]]==1) cnt++;
            if(cnt>k){
                mp[s[l]]--;
                if(mp[s[l]]==0) cnt--;
                l++;
            }
            if(cnt==k){
                maxi=max(maxi,r-l+1);
            }
            r++;
        }
        if(maxi==0) return -1;
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends