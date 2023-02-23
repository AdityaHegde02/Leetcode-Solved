//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int mod = 1e9 + 7;
    
    int solve(int x,int y,int n,int m,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(x >= n or y >= m or grid[x][y] == 0){
            return 0;
        }
        
        if(x == n - 1 and y == m - 1){
            return 1;
        }
        
        if(dp[x][y] != -1){
            return dp[x][y];
        }
       
        int a = solve(x + 1,y,n,m,grid,dp);
        int b = solve(x, y + 1,n,m,grid,dp);
        dp[x][y] = ((a + b)%mod);
        return dp[x][y] % mod;
    }
    
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>> dp(n+ 1,vector<int> (m+1,-1));
        if(grid[n - 1][m - 1] == 0 or grid[0][0] == 0){
            return 0;
        }
        return solve(0,0,n,m,grid,dp)%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends