//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<pair<int,int>>directions = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    void dfs(int i, int j,vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 'W'){
            return;
        }
        grid[i][j] = 'W';
        
        for(pair<int,int> p : directions){
            
            int nr = p.first + i;
            int nc = p.second + j;
            dfs(nr, nc, grid);
        }
        
        
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j< grid[0].size(); j++){
                if(grid[i][j] == 'L'){
                    dfs(i, j , grid);
                    count++;
                }
                
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends