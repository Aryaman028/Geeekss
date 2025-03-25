//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // SOLVING IT USING THE KAHN'S ALGORITHM
        // For this, we will use a slightly modified version 
        // of BFS where we will be requiring a queue data structure
        // an array that will store the indegree of each node. The 
        // indegree of a node is the number of directed edges incoming 
        // towards it.
        
        int n = adj.size();
        vector<int>inorder(n,0);
        
        //inorder vector
        for(auto v : adj){
            for(auto ele : v){
                inorder[ele]++;
            }
        }
        
        queue<int>q;
        for(int i = 0; i < n; i++){
            if(inorder[i] == 0)q.push(i);
        }
        
        vector<int>res;
        while(!q.empty()){
            int l = q.size();
            
            while(l--){
                
                int cur = q.front();
                q.pop();
                res.push_back(cur);
        
                for(auto ele : adj[cur]){
                    inorder[ele]--;
                    //whenever the inorder of any node gets zero push it
                    if(inorder[ele] == 0){
                        q.push(ele);
                    }
                }
                
            }
        }
        return res;
        


    }
};


//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
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
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends