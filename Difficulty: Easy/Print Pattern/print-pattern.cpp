//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int>res;
    void solve(int N,int x){
        if(x<=0){
            res.push_back(x);
            return;
        }
        res.push_back(x);
        solve(N,x-5);
        res.push_back(x);
        
    }
    vector<int> pattern(int N){
        solve(N,N);
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends