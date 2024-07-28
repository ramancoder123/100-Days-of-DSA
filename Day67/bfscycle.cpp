//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkCycle(int node, unordered_map<int, int> &parent, unordered_map<int, bool> &vis, queue<int> &q, vector<int> adj[]){
        q.push(node);
        parent[node] = -1;
        vis[node] = true;
        
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            
            for(int i = 0;i<adj[frontNode].size();i++){
                int neighbour = adj[frontNode][i];
                
                if(vis[neighbour] == true && neighbour != parent[frontNode]){
                    return true;
                }
                else if(!vis[neighbour]){
                    q.push(neighbour);
                    vis[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int, int> parent;
        unordered_map<int, bool> vis;
        queue<int> q;
        
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                bool ans = checkCycle(i, parent, vis, q, adj);
                
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
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends