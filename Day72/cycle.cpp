//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool cycleCheck(int node, unordered_map<int, bool> &vis, unordered_map<int, bool> &dfsCheck, vector<int> adj[]){
        vis[node] = true;
        dfsCheck[node] = true;
        
        for(int i = 0;i<adj[node].size();i++){
            int it = adj[node][i];
            if(!vis[it]){
                if(cycleCheck(it, vis, dfsCheck, adj)){
                    return true;
                }
            }
            else if(dfsCheck[it]){
                return true;
            }
        }
        dfsCheck[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int, bool> vis;
        unordered_map<int, bool> dfsCheck;
        
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                bool ans = cycleCheck(i, vis, dfsCheck, adj);
                
                if(ans == true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends