//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node, vector<vector<int>>&adj, vector<bool>&visited, stack<int>&s){
        visited[node] =true;
        
        for(int ele : adj[node]){
            if(!visited[ele]){
                dfs(ele, adj, visited, s);
            }
        }
        s.push(node);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //DFS - using stack to store the elements in it when all the operations
        // has been done on the node
        
        stack<int>s;
        vector<vector<int>>adj(V);
        
        for(int i = 0 ; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<bool>visited(V,false);
        for(int i = 0 ; i < V; i++){
            if(!visited[i]){
                dfs(i, adj, visited, s);
            }
        }
        vector<int>res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
        
        
    }
};


//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(V, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends