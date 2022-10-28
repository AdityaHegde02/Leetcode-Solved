class Solution {
public:
    int solve(int x,int y,int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(x == m-1 and y == n-1){
            return grid[x][y];
        }
        
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        
        int l = INT_MAX;
        int r = INT_MAX;
        
        if(x < m - 1){
            l = solve(x+1,y,m,n,grid,dp);
        }
        
        if(y < n - 1){
            r = solve(x,y+1,m,n,grid,dp);
        }
        
        return dp[x][y] = grid[x][y] + min(l,r);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        return solve(0,0,m,n,grid,dp);
    }
};