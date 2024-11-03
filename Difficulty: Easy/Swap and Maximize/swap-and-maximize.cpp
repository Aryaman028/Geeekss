//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<int>newarr(n);
        int left=0;
        int right = n-1;
        int i=0;
        while(left<=right){
            if(left==right){
                newarr[i++]=arr[left++];
            }else{
                newarr[i++]=arr[left++];
                newarr[i++]=arr[right--];
            }
        }
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+= abs(newarr[i]-newarr[(i+1)%n]);
        }
        return sum;
        // 1 4 7 9 20
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
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends