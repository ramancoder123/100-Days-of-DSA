//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
       
       //vector<int> vis(N,0);
       vector<int> ans(N,-1);
       queue<pair<int,int>> q;
       q.push({0,0});
       int nedges = M;
       
       vector<vector<pair<int,int>>> adjls(N);
       //vector<vector<int>> adjm(N,vector<int>(N,0));
       
       for(auto it : edges){
           
           adjls[it[0]].push_back({it[1],it[2]});
       }
       
       while(!q.empty()){
           
           int node = q.front().first;
           int dist = q.front().second;
           q.pop();
           
           if(ans[node] == -1 || dist < ans[node]){
               ans[node] = dist;
           }
           
           else{
               continue;
           }
           
           for(auto i : adjls[node]){
               q.push({i.first,dist+i.second});
                
           }
       }
       
       return ans;
       
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends