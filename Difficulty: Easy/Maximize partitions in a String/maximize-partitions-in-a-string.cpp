//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        unordered_map<char,int>m;
        
        for(int i = 0 ;i < s.length(); i++){
            m[s[i]]=i;
        }
        
        vector<int>v;
        for(int i = 0; i < s.length(); i++){
            int lastIndex = m[s[i]];
            string a = "";
            for(int j = i; j <= lastIndex; j++){
                if(lastIndex < m[s[j]]){
                    lastIndex = m[s[j]];
                }
                a += s[j];
            }
            i += a.length() - 1;
            v.push_back(a.length());
        }
        return v.size();
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends