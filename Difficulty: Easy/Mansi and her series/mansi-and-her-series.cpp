//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    bool isprime(int i){
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0)return false;
        }return true;
    }
    int nthprime(int n){
        int i=2;
        int c=0;
        while(true){
            if(isprime(i)){
                c++;
                if(c==n)return i;
            }
            i++;
        }return 0;
    }
    int nthTerm(int n){
        return nthprime(n)*n+n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n;
        Solution ob;
        cout<<ob.nthTerm(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends