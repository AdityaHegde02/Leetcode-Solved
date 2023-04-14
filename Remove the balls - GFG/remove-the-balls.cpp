//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        vector<int> final;
        final.push_back(0);
        for(int i = 1; i < N; i++){
            if(final.size() == 0){
                final.push_back(i);
            }
            else{
                if(color[final.back()] == color[i] and radius[final.back()] == radius[i]){
                    final.pop_back();
                }
                else{
                    final.push_back(i);
                }
            }
        }
        
        return final.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends