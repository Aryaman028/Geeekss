//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    void dfs(int node, vector<bool>&visited, stack<int>&st, vector<vector<pair<int,int>>>&adj){
        visited[node] = true;
        
        for(auto ele : adj[node]){
            if(!visited[ele.first]){
                dfs(ele.first, visited, st, adj);
            }
        }
        
        st.push(node);
    }
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        
        for(int i = 0 ; i < E; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        //topological sort karenge
        vector<bool>visited(V, false);
        
        stack<int>st;
        for(int i = 0 ; i < V; i++){
            if(!visited[i]){
                dfs(i, visited, st, adj);
            }
        }
        
        //we cant write INT_MAX as it will cause integer overflow on adding
        vector<int>dist(V,1e9);
        dist[0] = 0;
        
        
        while(!st.empty()){
            
            auto cur = st.top();
            st.pop();
            
            for(auto ele : adj[cur]){
                int neighbour = ele.first;
                int wt = ele.second;
                
                if(wt + dist[cur] < dist[neighbour]){
                    dist[neighbour] = wt + dist[cur];
                }
            }
        }
        
        for(int i = 0; i < V; i++){
            if(dist[i] == 1e9)dist[i] = -1;
        }
        return dist;
        
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
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends