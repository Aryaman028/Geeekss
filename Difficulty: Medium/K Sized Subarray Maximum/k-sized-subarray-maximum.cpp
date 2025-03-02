//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int>q;
        vector<int>res;
        int n = arr.size();
        for(int i=0;i<k;i++){
            while(!q.empty() &&  arr[q.back()] <= arr[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        
        for(int i = k; i < n; i++){
            
            res.push_back(arr[q.front()]);
            while(!q.empty() &&  (i - q.front())>= k){
                q.pop_front();
            }
            
            
            while(!q.empty() && arr[q.back()] <= arr[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        res.push_back(arr[q.front()]);
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends