//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        int n = s.size();
        int beauty = 0;
        for(int i = 0; i < n; i++){
            vector<int> count(26,0);
            count[s[i] - 'a']++;
            for(int j = i + 1; j < n; j++){
                count[s[j] - 'a']++;
                int mn = INT_MAX;
                int mx = INT_MIN;
                for(auto &i : count){
                    if(i != 0){
                        mn = min(mn,i);
                        mx = max(mx,i);
                    }
                }
                beauty += mx - mn;
            }
        }
        return beauty;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends