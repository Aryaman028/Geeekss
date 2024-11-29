//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
       //using tabulation
       int n = s1.length();
       int m = s2.length();
       
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       for(int i=0;i<=n;i++){
           dp[i][0]=i;
       }
        for(int i=0;i<=m;i++){
           dp[0][i]=i;
       }
       
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               if(s1[i-1]==s2[j-1]){
                   dp[i][j] = dp[i-1][j-1];
               }else dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
           }
       }
       return dp[n][m];
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends