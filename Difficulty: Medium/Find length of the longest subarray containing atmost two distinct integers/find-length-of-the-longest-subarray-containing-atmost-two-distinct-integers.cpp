//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        // BRUTE FORCE
        
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            set<int>s;
            for(int j = i; j < n; j++){
                
                s.insert(arr[j]);
                
                if(s.size() <= 2){
                    ans = max(ans , j - i + 1);
                }else break;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends