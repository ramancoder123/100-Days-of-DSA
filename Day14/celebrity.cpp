//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    private: 
    bool knows(vector<vector<int> >& M, int A, int B, int n){
        if(M[A][B] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        stack<int> st;
        // Step1 : Push all elements of matrix to a stack
        for(int i = 0;i<n;i++){
            st.push(i);
        }
        
        // step 2: Get top two elemens and do comaprisons 
        while(st.size() > 1){
            int A = st.top();
            st.pop();
            
            int B = st.top();
            st.pop();
            
            if(knows(M, A, B, n)){
                st.push(B);
            }
            else{
                st.push(A);
            }
        }
        
        int candidate = st.top();
        
        // step 3: Validity check
        
        // rowcheck
        
        bool rowCheck = false;
        int zeroCount = 0;
        
        for(int i = 0;i<n;i++){
            if(M[candidate][i] == 0){
                zeroCount++;
            }
        }
        
        if(zeroCount == n){
            rowCheck = true;
        }
        
        int colCheck = false;
        int colCount = 0;
        
        for(int i = 0;i<n;i++){
            if(M[i][candidate] == 1){
                colCount++;
            }
        }
        
        if(colCount == n-1){
            colCheck = true;
        }
        
        if(rowCheck && colCheck){
            return candidate;
        }
        else{
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends