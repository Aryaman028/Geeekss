//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User Function Template
// class Solution {
//   public:
//     // Function to find the shortest distance of all the vertices
//     // from the source vertex src.
//     vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
//         // Code here
//         // priority_queue requires a container (like vector) as the second argument.
//         // The default container is vector<T>, so you need to specify it explicitly when using greater<T>.
        
//         priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;
        
//         pq.push({0,src});
        
//         vector<int>dist(adj.size(), 1e9);
//         dist[src] = 0;
        
//         while(!pq.empty()){
            
//             int d = pq.top().first;
//             int node = pq.top().second;
//             pq.pop();
            
//             for(auto ele: adj[node]){
//                 int neighbour = ele.first;
//                 int wt = ele.second;
                
//                 //when we are getting a smaller value then only we are pushing
//                 //to the priority queue
//                 if(wt + d < dist[neighbour]){
//                     pq.push({wt + d, neighbour});
//                     dist[neighbour] = wt + d;
//                 }
                
//             }
//         }
//         return dist;
        
        
//     }
// };
class Solution {
  public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        //USING SET 
        
        //USING SET WE CAN REMOVE THE EXISTING PATH
        // {4,5} AYA 5TH NODE PE AUR DIST[5] = 10 THEN WE KNOW THAT DIST[5] IS NOT
        // INIFINITE THUS SOMEONE HAS VISITED THEN IT WILL BE INSIDE THE SET
        // AND IT IS HAVING DIST GREATER THAN THA {4,5} HENCE WE WILL REMOVE
        // THE EXISTING {10,5} IN THE SET AND INSERT {4,5} FOR FURTHER PATH
        // AS THERE WILL BE NO USE OF {10,5}
        // BUT IN PRIORITY QUEUE WE AGAIN GO TO {10,5} AS WE CANT DELETE IN PQ
        
        int n = adj.size();
        set<pair<int,int>>st;
        // {dist,node}
        vector<int>dist(n, 1e9);
        
        st.insert({0,src});
        dist[src] = 0;
        
        while(!st.empty()){
            auto cur = *(st.begin());
            
            int node = cur.second;
            int d = cur.first;
            
            st.erase(cur);
            
            for(auto ele : adj[node]){
                int neigh = ele.first;
                int wt = ele.second;
                
                if(wt + d < dist[neigh]){
                    if(dist[neigh] != 1e9){
                        st.erase({dist[neigh], neigh});
                    }
                    dist[neigh] = wt + d;
                    st.insert({wt+d, neigh});
                }
            }
        }
        for(int i = 0 ; i < n; i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        return dist;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends