//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        // Code here
        vector<int> dis(V, 1e9);
        set<pair<int, int>> st;
    
        dis[S] = 0;
        st.insert({0, S});
    
        while (!st.empty())
        {
            auto it = *st.begin();
            st.erase(st.begin());
    
            int node = it.second;
            int distance = it.first;
    
            if (distance > dis[node])
                continue;
    
            for (auto edge : adj[node])
            {
                int adjNode = edge[0];
                int edgeWeight = edge[1];
    
                if (dis[node] + edgeWeight < dis[adjNode])
                {
                    dis[adjNode] = dis[node] + edgeWeight;
                    st.insert({dis[adjNode], adjNode});
                }
            }
        }
    
        return dis;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends