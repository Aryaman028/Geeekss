//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<string>st;
        stack<int>num;
        int curNum = 0;
        string curString = "";
        
        for(int i = 0; i < s.length(); i++){
            char v = s[i];
            if(isdigit(v)){
                curNum = 10 * curNum + (v - '0');
                
            }else if(v == '['){
                num.push(curNum);
                st.push(curString);
                curNum = 0;
                curString = "";
                
            }else if(v == ']'){
                string temp = curString;
                int repeat = num.top(); num.pop();
                curString = st.top(); st.pop();
                
                while(repeat--){
                    curString += temp;
                }
            }
            else{
                curString += v;   //Normal characters    
            }
            
        }
        return curString;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends