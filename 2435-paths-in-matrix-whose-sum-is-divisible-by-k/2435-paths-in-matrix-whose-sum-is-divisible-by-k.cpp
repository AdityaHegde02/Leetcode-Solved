class Solution {
public:
    int mod = 7 + 1e9;
    
    int solve(int i,int j,int currSum,int k,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        if(i >= grid.size() or j >= grid[0].size()){
            return 0;
        }    
        
        currSum += grid[i][j];
        
        if(i == grid.size() - 1 and j == grid[0].size() - 1){
            return ((currSum) % k == 0);
        }
        
        if(dp[i][j][(currSum) % k] != -1){
            return dp[i][j][(currSum) % k];
        }
    
        // right
        int a = solve(i,j + 1,(currSum) % k,k,grid,dp);
        
        // down
        int b = solve(i + 1,j,(currSum) % k,k,grid,dp);
        
        return dp[i][j][(currSum) % k] = (a + b)%mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m + 1,vector<vector<int>> (n + 1,vector<int> (k + 1,-1)));
        return solve(0,0,0,k,grid,dp);
    }
};