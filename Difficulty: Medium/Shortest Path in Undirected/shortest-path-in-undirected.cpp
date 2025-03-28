//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

//Back-end complete function Template for C++


// } Driver Code Ends

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        
        //WE CAN DO IT BY DOINING BFS TRAVERSAL
        //storing the wt with the node in the queue
        
        int n = adj.size();
        queue<pair<int,int>>q;
        
        q.push({src,0});
        
        vector<bool>visited(n,false);
        
        vector<int>res(n,-1);
        
        visited[src] = true;
        while(!q.empty()){
            int l = q.size();
            
            while(l--){
                int node = q.front().first;
                int dist = q.front().second;
                res[node] = dist;
                q.pop();
                
                for(auto ele: adj[node]){
                    if(!visited[ele]){
                        visited[ele] = true;
                        q.push({ele, dist + 1});
                    }
                }
                
            }
        }
        return res;
        
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
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends