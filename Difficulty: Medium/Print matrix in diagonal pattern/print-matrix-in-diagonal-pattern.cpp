//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        vector<int>v;
        int m= mat.size();  //row
        int n = mat[0].size();       //col
        int row = 0;
        int col=0;
        while(row<m && col<n){
            
            //down to up
            while(col<n && row>=0 && row<m && col>=0){        
                v.push_back(mat[row--][col++]);    //take care of the increment and decrement wisely
            }
            if(col==n){    //[lower triangle]  
                row+=2;
                col--;
            }
            else row++;    //[upper triangle]
            
            //top to down
            while(row<m && col>=0 && row>=0 && col<n){
                v.push_back(mat[row++][col--]);   //as it is post operator thus it is facing issue
            }
            if(row==m){   //[lower triangle]
                col+=2;
                row--;
            }
            else col++;  //[upper triangle] 
        }
        return v;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends