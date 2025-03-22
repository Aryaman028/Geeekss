//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& mat) {
        // Code here
        
        //MULTISOURCE BFS APPLY
        int m = mat.size();
        int n = mat[0].size();
        
        // {{row,col},set}
        queue<pair<pair<int,int>,int>>q;
        vector<pair<int,int>>directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        vector<vector<int>>dist(m,vector<int>(n,-1));


        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    q.push({{i,j},0});
                    visited[i][j] = true;
                }
            }
        }
        // Now start BFS on the multisource
        
        while(!q.empty()){
            int l = q.size();
            
            while(l--){
                int row = q.front().first.first;
                int col = q.front().first.second;
                int set = q.front().second;
                
                q.pop();
                
                dist[row][col] = set;
                //traverse in every directions
                for(pair<int,int> p: directions){
                    int newRow = row + p.first;
                    int newCol = col + p.second;
                    
                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n){
                        if(visited[newRow][newCol] == false){
                            q.push({{newRow,newCol},set + 1});
                            visited[newRow][newCol] = true;
                        }
                    }
                }
            }
        }
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << "\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends