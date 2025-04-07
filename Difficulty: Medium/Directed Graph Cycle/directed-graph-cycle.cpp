//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        //Using kahn's algo
        
        vector<vector<int>>adj(V);
        vector<int>indegree(V,0);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i = 0 ; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int c = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            c++;
            for(int ele: adj[cur]){
                indegree[ele]--;
                if(indegree[ele] == 0){
                    q.push(ele);
                }
            }
        }
        
        if(c != V)return true;
        return false;
        
        
        
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends