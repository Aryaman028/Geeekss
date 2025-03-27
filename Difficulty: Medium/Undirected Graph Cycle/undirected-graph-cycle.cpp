//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int node, int parent, vector<bool>&visited, vector<vector<int>>& adj ){
        visited[node] =true;
        
        for(auto ele : adj[node]){
            if(!visited[ele]){
                if(dfs(ele, node, visited, adj))return true;
            }else if(ele != parent){
                return true;
            }
        }
        return false;
    }  
    // bool check(int node, vector<bool>&visited, vector<vector<int>>& adj){
    //     queue<pair<int,int>>q;
        
    //     q.push({node,-1});
    //     visited[node] = true;
        
    //     while(!q.empty()){
            
    //         auto cur = q.front();
    //         int parent = cur.second;
    //         int node = cur.first;
    //         q.pop();
            
    //         for(auto ele: adj[node]){
    //             if(visited[ele]==false){
    //                 visited[ele] = true;
    //                 q.push({ele,node});
    //             }else{
    //                 if(parent != ele){
    //                     return true;
    //                 }
    //             }
    //         }   
    //     }
    //     return false;
    // }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        
        int n = adj.size();
        
        vector<bool>visited(n,false);
        
        // we are pushing the parent and the node in the 
        // queue so that we can check that if the neighbour is 
        // visited then it is becuase of parent or is it the
        // neighbour of someoneelse node
        
        // {node,parent}
        
        // BFS TRAVERSAL
        // for(int i = 0; i < n; i++){
        //     if(visited[i] == false){
        //         if(check(i, visited,adj))return true;
        //     }
        // }
        
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                if(dfs(i,-1, visited,adj))return true;
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
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends