class Solution {
    int dfs(int i, int j , vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m){
        
        if(i >= 0 and i < n and j >= 0 and j < m and vis[i][j] == 0 and grid[i][j] != 0){
            int res =0;
            vis[i][j] = 1;
            res = max({res,dfs(i+1,j,vis,grid,n,m),dfs(i-1,j,vis,grid,n,m), dfs(i,j+1,vis,grid,n,m), dfs(i,j-1,vis,grid,n,m)});
            vis[i][j] = 0;
            return grid[i][j] + res;
        }
        
        return 0;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n , vector<int> (m, 0));
        int ans = 0;
        for(int i = 0 ;i < n;i++){
            for(int j =0 ;j<m;j++){
                ans = max(ans , dfs(i, j, vis, grid, n, m));   
            }
        }
        return ans;
    }
};