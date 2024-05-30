//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s){
        string ans;
        stack<int> st;
        
        for(int i=0;i<s.size();i++){
            if(s[i]!='.'){
                st.push(s[i]);
            }
            
            else{
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            ans.push_back('.');
        }
    }
        
        while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends