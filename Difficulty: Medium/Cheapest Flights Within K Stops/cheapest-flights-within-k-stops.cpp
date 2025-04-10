//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<vector<pair<int,int>>>adj(n);
        
        for(int i = 0; i < flights.size(); i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            
            adj[u].push_back({v,wt});
        }
        // we are using simple as the stop is increasing monotonicaly by one thus
        //to eliminate the comp of O(logn) of the push and pop of pq;
        
        queue<pair<int , pair<int,int>>>q;
        // {stop, {node,dist}};
        q.push({0,{src,0}});
        vector<int>dist(n, 1e9);
        
        dist[src] = 0;
        
        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int d = q.front().second.second;
            q.pop();
            
            for(auto ele : adj[node]){
                int v = ele.first;
                int wt = ele.second;
                int res = wt + d;
                if(res < dist[v] && stop <= K){
                    dist[v] = res;
                    q.push({stop+1, {v, res}});
                }
            }
        }
        if(dist[dst] == 1e9)return -1;
        
        return dist[dst];
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends