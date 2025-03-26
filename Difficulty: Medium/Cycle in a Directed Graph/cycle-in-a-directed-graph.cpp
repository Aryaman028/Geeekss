//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<bool>&visited, vector<bool>&curPath, vector<vector<int>> &adj){
        visited[node] = true;
        curPath[node] = true;
        
        for(auto ele : adj[node]){
            if(!visited[ele]){
                if(dfs(ele,visited,curPath,adj))return true;
            }else if(curPath[ele]){
                return true;
            }
        }
        curPath[node] = false;
        return false;
    }
    bool isCyclic(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<bool>visited(n,false);
        vector<bool>curPath(n,false);
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(dfs(i, visited, curPath, adj))return true;
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

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends