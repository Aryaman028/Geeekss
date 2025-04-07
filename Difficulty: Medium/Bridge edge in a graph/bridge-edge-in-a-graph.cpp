//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    void dfs(int node, vector<vector<int>>&adj, vector<bool>&v ){
        v[node] = true;
        
        for(auto ele : adj[node]){
            if(!v[ele]){
                dfs(ele, adj,v);
            }
        }
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<vector<int>>adj1(V);
        vector<vector<int>>adj2(V);
        for(int i = 0 ; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(!(u == c && v == d) || (u == d && v == c)){
                adj2[u].push_back(v);
                adj2[v].push_back(u);
            }
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        
        int c1 = 0;
        vector<bool>visited1(V,false);
        for(int i = 0; i < V; i++){
            if(!visited1[i]){
                dfs(i,adj1,visited1);
                c1++;
            }
        }
        
        vector<bool>visited2(V,false);
        int c2 = 0;
        for(int i = 0; i < V; i++){
            if(!visited2[i]){
                dfs(i,adj2,visited2);
                c2++;
            }
        }
        if(c1 == c2)return false;
        return true;
        
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
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends