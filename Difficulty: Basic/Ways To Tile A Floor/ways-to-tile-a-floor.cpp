//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int numberOfWaysHelper(int n, vector<int>& dp) {
        if (n <= 2) return n;

        // Check if already calculated
        if (dp[n] != -1) return dp[n];

        // Compute and store in dp
        dp[n] = numberOfWaysHelper(n - 1, dp)%1000000007 + numberOfWaysHelper(n - 2, dp)%1000000007;
        return dp[n];
    }

    int numberOfWays(int n) {
        vector<int> dp(n + 1, -1); // Initialize dp array
        int res = numberOfWaysHelper(n, dp)%1000000007;
        return res;
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.numberOfWays(n) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends