class Solution {
public:
    vector<int> dir = {-1,0,1,0,-1};
    int dp[501][501][6];
    
    bool dfs(int i,int j,int d,vector<vector<char>> &grid,vector<vector<int>> &vis){
        if(dp[i][j][d + 1] != -1){
            return dp[i][j][d + 1];
        }
        vis[i][j] = 1;
        
        int nocheck = -1;
        if(d == 0){
            nocheck = 2;
        }
        if(d == 1){
            nocheck = 3;
        }
        if(d == 2){
            nocheck = 0;
        }
        if(d == 3){
            nocheck = 1;
        }
        
        for(int k = 0; k < 4; k++){
            if(k != nocheck){
                int ni = i + dir[k], nj = j + dir[k + 1];
                if(ni >= 0 and nj >= 0 and ni < grid.size() and nj < grid[0].size() and grid[ni][nj] == grid[i][j]){
                    if(vis[ni][nj]){
                        return dp[i][j][d + 1] = true;
                    }
                    if(dfs(ni,nj,k,grid,vis)){
                        return dp[i][j][d + 1] = true;
                    }
                }
            }
        }
        
        return dp[i][j][d + 1] = false;
    }
        
    bool containsCycle(vector<vector<char>>& grid) {
       int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        memset(dp,-1,sizeof(dp));
       for(int i = 0; i < m; i++){
           for(int j = 0; j < n; j++){
               if(!vis[i][j]){
                   if(dfs(i,j,-1,grid,vis)){
                       return true;
                   }
               }
           }
       } 
       return false;
    }
};