//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &arr) {
        stack<int> st;
        
        for(int i = 0;i<arr.size();i++){
            
            while(!st.empty() && arr[i] < 0 && st.top() > 0){
                int sum = arr[i] + st.top();
                
                if(sum < 0){
                    st.pop();
                }
                else if(sum > 0){
                    arr[i] = 0;
                }
                else{
                    st.pop();
                    arr[i] = 0;
                }
            }
            if(arr[i] != 0){
                st.push(arr[i]);
            }
        }
        
        int s = st.size();
        vector<int> result(s);
        
        int i = s-1;
        while(!st.empty()){
            result[i] = st.top();
            st.pop();
            i--;
        }
        return result;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends