//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        vector<int> ans(2, -1);
        
        int i = 0;
        int j = n - 1;
        int count = 0;
        
        for(int i = 0;i<n;i++){
            if(arr[i] == x && count == 0){
                count++;
                ans[0] = i;
            }
            
            if(arr[i] == x && count >= 1){
                count++;
                ans[1] = i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends