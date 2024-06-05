//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long long getMin(long long A[], long long B[], long long n)
    {
        vector<pair<int, int>> p1;
        vector<pair<int, int>> p2;
        
        if(n == 1){
            return -1;
        }
        
        for(int i = 0;i<n;i++){
            p1.push_back(make_pair(A[i], i));
        }
        
        for(int j = 0;j<n;j++){
            p2.push_back(make_pair(B[j], j));
        }
        
        sort(p1.begin(), p1.end());
        sort(p2.begin(), p2.end());
        
        if(p1[0].second != p2[0].second){
            return p1[0].first + p2[0].first;
        }
        else{
            long long a = p1[0].first + p2[1].first;
            long long b = p1[1].first + p2[0].first;
            
            return a < b ? a : b;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long n, i;
        cin>>n;
        long long A[n+1], B[n+1];
        for(i=0;i<n;i++)
        cin>>A[i];
    
        for(i=0;i<n;i++)
        cin>>B[i];
        Solution ob;
        cout<< ob.getMin(A, B, n) <<endl;
    }
}

// } Driver Code Ends