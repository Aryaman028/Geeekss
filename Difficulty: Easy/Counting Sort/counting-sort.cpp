//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        // code here
        vector<int>fre(26,0);
        for(int i=0;i<arr.size();i++){
            fre[arr[i]-97]++;
        }
        string res = "";
        for(int i=0;i<26;i++){
            while(fre[i]!=0){
                res+=i + 97;
                fre[i]--;
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends