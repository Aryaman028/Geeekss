//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int memo(int i,int prev, vector<int>&arr, vector<vector<int>>&dp){
        if(i >= arr.size())return 0;
        if(i == arr.size() - 1){
            return arr[i] > arr[prev];
        } 
        
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        int pick=0;
        if(prev == -1 || arr[prev] < arr[i]){
            pick = 1 + memo(i+1,i,arr,dp);
        }
        int notPick = memo(i+1,prev,arr,dp);
        
        return dp[i][prev+1] =  max(pick,notPick);
    }
  
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        int prev =-1;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return memo(0,prev,arr,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends