//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        set<string>s(wordList.begin(),wordList.end());
        
        queue<pair<string,int>>q;
        
        q.push({startWord,1});
        
        while(!q.empty()){
            int l = q.size();
            pair<string,int>p = q.front();
            string word = p.first;
            int val = p.second;
            q.pop();
            if(word == targetWord){
                return val;
            }
            while(l--){
                for(int j = 0; j < word.length(); j++){
                    string temp = word;
                    for(int i = 97; i <= 122; i++){
                        temp[j] = (char)i;
                        if(s.count(temp)>0){
                            q.push({temp,val+1});
                            s.erase(temp);
                        }
                    }
                }
                
            }
            
        }
        return 0;
        
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends