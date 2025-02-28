//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool memo(int n,vector<int>&arr, int target,vector<vector<int>>&dp){
       if(target==0)return true;
       
       if(n==0)return target == arr[0];
        
        if(dp[n][target] != -1)return dp[n][target];
        
        bool take = false;
        if(target >= arr[n]) take = memo(n - 1,arr,target - arr[n],dp);
        
        bool nottake = memo(n - 1,arr,target,dp);
        
        return  dp[n][target] = (take | nottake);
    }
  
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        
        return memo(n-1,arr,target,dp);
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
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends