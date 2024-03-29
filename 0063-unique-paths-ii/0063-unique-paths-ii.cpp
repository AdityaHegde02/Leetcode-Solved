class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>> &dp,vector<vector<int>> &grid){
        if(i >= m or j >= n or grid[i][j] == 1){
            return 0;
        }
        
        if(i == m - 1 and j == n - 1){
            return 1;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = solve(i,j + 1,m,n,dp,grid);
        int down = solve(i + 1,j,m,n,dp,grid);
        
        return dp[i][j] = right + down;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(101,vector<int> (101,-1));
        return solve(0,0,m,n,dp,grid);
    }
};