class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>> &dp){
        if(i >= m or j >= n){
            return 0;
        }
        
        if(i == m - 1 and j == n - 1){
            return 1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = solve(i,j + 1,m,n,dp);
        int down = solve(i + 1,j,m,n,dp);
        
        return dp[i][j] = right + down;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(101,vector<int> (101,-1));
        return solve(0,0,m,n,dp);
    }
};