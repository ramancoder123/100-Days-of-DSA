//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool checkBipartite(int node, vector<int> adj[], vector<int> &color){
        for(int j = 0;j<adj[node].size();j++){
            // color is not assigned to the neighbour
            if(color[adj[node][j]] == -1){
                color[adj[node][j]] = (color[node] + 1)%2;
                
                if(!checkBipartite(adj[node][j], adj, color)){
                    return false;
                }
            }
    
            // color is assigned
            else{
                if(color[node] == color[adj[node][j]]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int>adj[]){
        vector<int> color(V, -1);
        
        for(int i = 0;i<V;i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!checkBipartite(i, adj, color)){
                    return false;
                }
            }
        }
        return true;
    }
};

// bool isBipartite(int V, vector<int>adj[]){
// 	    vector<int> color(V, -1);
// 	    queue<int> q;
	    
// 	    for(int i =0;i<V;i++){
// 	        if(color[i] == -1){
// 	            q.push(i);
// 	            color[i] = 0;
	            
// 	            while(!q.empty()){
// 	                int frontNode = q.front();
// 	                q.pop();
	                
// 	                for(int j = 0;j<adj[frontNode].size();j++){
// 	                    // not traversed
// 	                    if(color[adj[frontNode][j]] == -1){
// 	                        color[adj[frontNode][j]] = (color[frontNode] + 1)%2;
// 	                        q.push(adj[frontNode][j]);
// 	                    }
	                    
// 	                    else{
// 	                        if(color[frontNode] == color[adj[frontNode][j]]){
// 	                            return false;
// 	                        }
// 	                    }
// 	                }
// 	            }
// 	        }
// 	    }
// 	    return true;
// 	}

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends