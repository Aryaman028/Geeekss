//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int memo(int n, int sum, vector<int>&arr, vector<vector<int>>&dp){
        if(n == 0){
            if(arr[0] == 0 && sum == 0)return 2;
            if(sum == 0 || sum == arr[0])return 1;
            return 0;
        }
        
        if(dp[n][sum] != -1)return dp[n][sum];
        
        int pick = 0;
        
        if(sum >= arr[n]){
            pick = memo(n - 1,sum - arr[n], arr, dp);
        }
        int notPick = memo(n - 1, sum, arr, dp);
        
        return dp[n][sum] = pick + notPick;
        
        
    }
  
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        
        int n = arr.size();
        
        int tSum = 0;
        
        for(int i = 0; i < n;i++){
            tSum += arr[i];
        }
        
        if((tSum - d) % 2 != 0) return 0;
        
        int sum = (tSum - d) / 2;
        if(sum < 0)return 0;
        
        vector<vector<int>>dp(n, vector<int>(sum + 1, -1));
        
        return memo(n - 1, sum, arr,dp);
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends