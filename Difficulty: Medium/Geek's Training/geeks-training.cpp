//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int geek(int day,int last,vector<vector<int>>& arr,vector<vector<int>>&dp){
        if(day==0){
           int maxi=0;
           for(int i=0;i<3;i++){
               if(i!=last)maxi = max(arr[day][i],maxi);
           }
           return maxi;
        }
        if(dp[day][last]!=-1)return dp[day][last];
        
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                int sum = arr[day][i] + geek(day-1,i,arr,dp);
                maxi = max(sum,maxi);
            }
        }
        return dp[day][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        vector<vector<int>>dp(arr.size(),vector<int>(4,-1));
        return geek(arr.size()-1,3,arr,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends