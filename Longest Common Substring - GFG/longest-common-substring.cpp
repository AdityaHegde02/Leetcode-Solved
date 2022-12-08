//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int ans = 0;
    
    int solve(string &x,string &y,int n,int m,vector<vector<int>> &dp){
        if(n == 0 || m == 0){
            return 0;
        }
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        int temp = 0;
        if(x[n - 1] == y[m - 1]){
            temp = 1 + solve(x,y,n-1,m-1,dp);
        }

        solve(x,y,n-1,m,dp);
        solve(x,y,n,m-1,dp);
        ans = max(ans,temp);
        return dp[n][m] = temp;
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        solve(S1,S2,n,m,dp);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends