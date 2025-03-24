//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  int count(int i, string &digits,vector<int>&dp){
      if(i == digits.size())return 1;
      if(digits[i] == '0')return 0;
      
      if(dp[i] != -1)return dp[i];
      
      int x = count(i+1,digits,dp);
      int y = 0;
      if(i < (digits.size()-1) && (digits[i]=='1' || digits[i]=='2' && digits[i+1] <='6')){
          y = count(i + 2,digits,dp);
      }
      return dp[i] = (x + y);
      
  }
    int countWays(string &digits) {
        // Code here
        int n = digits.size();
        vector<int>dp(n,-1);
        return count(0,digits,dp);
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends