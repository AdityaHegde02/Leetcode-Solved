class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(i >= n){
            return 0;
        }    
        
        if(j != -1 and dp[i][j] != INT_MAX){
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        for(int k = 0; k < n; k++){
            if(k != j)
                ans = min(ans,grid[i][k] + solve(i + 1,k,n,grid,dp));
        }
        if(j == -1){
            return ans;
        }
        return dp[i][j] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n+1,vector<int> (n + 1,INT_MAX));
        return solve(0,-1,n,grid,dp);
    }
};