//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        int n = s.size();
        int mx = 0;
        string left;
        for(int i = 0; i < n; i++){
            left += s[i];
            string b = s.substr(i + 1,i + 1);
            if(left == b){
                mx = max(mx,i + 1);
            }
        }
        return (mx == 0)? n : (n - mx + 1);
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
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends