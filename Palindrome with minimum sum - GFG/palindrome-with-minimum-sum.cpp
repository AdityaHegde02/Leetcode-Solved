//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while(i <= j){
            if(s[i] != '?' and s[j] == '?'){
                s[j] = s[i];
            }
            if( s[i] == '?' and s[j] != '?'){
                s[i] = s[j];
            }
            if(s[i] != '?' and s[j] != '?'){
                if(s[i] != s[j]){
                    return -1;
                }
            }
            i++;
            j--;
        }
        
        int ans = 0;
        string t = "";
        for(int i = 0; i < n; i++){
            if(s[i] != '?'){
                t += s[i];
            }
        }
        
        if(t == ""){
            return 0;
        }
        
        for(int i = 0; i < t.size() - 1; i++){
            ans += abs((t[i + 1] - '0') - (t[i] - '0'));
        }
        
        return ans;
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
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends