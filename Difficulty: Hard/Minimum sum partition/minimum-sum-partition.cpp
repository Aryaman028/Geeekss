//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class Solution {

//   public:
//     int minDifference(vector<int>& arr) {
//         // Your code goes here
//     }
// };

class Solution {
public:
    int minDifference(vector<int>& nums) {

        //USING THE TABULATION APPROACH DIRECTLY AS THE LAST ROW OF THE TABLE WHEN WE CALCULATE THE TARGET SUM IS POSSIBLE OR NOT IN THE SUBARRAY
        //THE LAST ROW CONTAINS TRUE IF THE COL SUM IS POSSIBLE BY THE ARRAY

        // ARR = [3,2,5]  TOTALSUM = 10
        // DP[N-1][COL]  AT EVERY COL = 0,1,2,3,4,6,7,8,9,10

        // IF(DP[N-1][3]==TRUE)  THEN SUM 3 IS THE SUM OF SUBSET1
        // IF(DP[N-1][5]==TRUE)  THEN SUM 5 IS THE SUM OF SUBSET1
        // CONSIDER ALL THE SUBSET1 SUMS AND THE SUBTRACT FROM THE TOTAL AND GET THE MINIMAL


        int n = nums.size();
        int totalSum = 0;
        for(int ele:nums){
            totalSum += ele;
        }
        vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));
        //base case
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        if(nums[0]<=totalSum && nums[0] >= 0){
            dp[0][nums[0]] = true;
        }
        for(int i = 1; i < n ; i++ ){
            for(int j = 0; j <= totalSum; j++ ){
                bool pick = false;
                if(j >= nums[i]) pick = dp[i-1][j - nums[i]];
                bool notPick = dp[i-1][j];
                dp[i][j] = pick || notPick;
            }
        }

        //traversing the last row to see the sum of the subset1 and then subtracting from the total sum to get the subset2 sum and then getting the minimal from the diff
        int sum1 = 0;
        int sum2 = 0;
        int mini = INT_MAX;
        for(int  i = 0; i <= totalSum/2; i++){
            if(dp[n-1][i]){
                sum1 = i;
                sum2 = totalSum - sum1;
                mini = min(abs(sum1-sum2),mini);
            }
        }
        return mini;
    }
};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int ans = ob.minDifference(arr);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends