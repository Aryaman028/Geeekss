//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}};

  void dfs(int i, int j,int baseRow, int baseCol, vector<vector<int>>& grid, vector<pair<int,int>>&shape){
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j] = 0;
        shape.push_back({i - baseRow, j - baseCol});

        for(pair<int,int> p: dir){
            int nr = p.first + i;    //new row
            int nc = p.second + j;    //new col

            if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1){
                dfs(nr, nc, baseRow, baseCol, grid, shape);
            }
        }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        //First you will think of counting the nodes in one componet and
        //then sotring in the set and return the set size which will be
        // wrong as we have to take care of the shape of the island also
        // 1 1 0 0
        // 1 0 0 0
        // 0 0 0 1
        // 0 0 1 1
        // this case will be having 2 as answer
        
        
        //we will be storing the shape of the dfs 
        //traversal of the node in the set to remove the duplicates
        
        //To store the shape subtract the base row and col from
        // each node while traversal to get the relative coordinates
        // wrt to the base row and base col
        
        
        int m = grid.size();
        int n = grid[0].size();
        // code here
        set<vector<pair<int,int>>>s;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    vector<pair<int,int>>shape;
                    dfs(i,j,i,j,grid,shape);
                    s.insert(shape);
                }
            }
        }
        return s.size();
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends