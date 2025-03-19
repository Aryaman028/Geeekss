//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        // Code here
        // int n = nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n,-1);
        
        int lastEle = 0;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i] && (1 + dp[prev]) > dp[i]){
                    hash[i] = prev;
                    dp[i] = 1 + dp[prev];
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastEle = i;
            }
        }
        vector<int>res;
        
        
        while(lastEle != -1){
            
            res.push_back( nums[lastEle] );
            lastEle = hash[lastEle];
        }
        reverse(res.begin(),res.end());
        
        return res;
    
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends