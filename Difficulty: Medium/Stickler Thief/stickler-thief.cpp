//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
  int memo(int n, vector<int>&arr, vector<int>&dp){
      if(n == 0){
          return arr[n];
      }
      if(n < 0)return 0;
      
      if(dp[n] != -1)return dp[n];
      
      int pick = arr[n] + memo(n - 2, arr, dp);
      int notPick = memo(n - 1, arr, dp);
      
      return dp[n] = max(pick, notPick);
  }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>dp(n, -1);
        return memo(n - 1, arr, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends