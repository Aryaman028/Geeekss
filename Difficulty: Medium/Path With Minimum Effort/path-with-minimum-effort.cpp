//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends


class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        vector<pair<int,int>>directions = {{1,0}, {-1,0}, {0,-1}, {0,1}};
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;


        vector<vector<int>>dist(m, vector<int>(n,1e9));


        // {dist, {row,col}};
        pq.push({0, {0,0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            pq.pop();

            if(row==m-1 && col==n-1){
                return d;
            }

            for(pair<int,int> p : directions){
                int newrow = row + p.first;
                int newcol = col + p.second;

                if(newrow >= 0 && newrow < m && newcol >= 0 && newcol < n){

                    // we fount the wt between the adjascent cells but in the question it is given that maximum absolute difference is considered thus also computed neweffort which stores the maximum absolute difference in it coming from the path

                    //only this part is tricky
                    int edgeWt = abs(heights[row][col] - heights[newrow][newcol]);
                    int neweffort = max(edgeWt,d);
                    

                    if(neweffort < dist[newrow][newcol]){
                        pq.push({neweffort, {newrow, newcol}});
                        dist[newrow][newcol] = neweffort;
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends