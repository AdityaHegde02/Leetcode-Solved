//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string> ans;
        unordered_map<string,vector<string>> mp;
        
        for(auto &i : Dictionary){
            string x = i;
            string y = "";
            for(auto &j : x){
                if(j >= 65 and j <= 90){
                    y += j;
                }
            }
            mp[y].push_back(x);
        }
        
        vector<string> final;
        for(auto &i : mp){
            string x = i.first;
            string temp = x.substr(0,Pattern.size());
            if(temp == Pattern){
                for(auto &j : i.second){
                    final.push_back(j);
                }
            }
        }
        
        sort(final.begin(),final.end());
        
        if(final.size() == 0){
            return {"-1"};
        }
        
        return final;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends