class Solution {
public:
    vector<int> dir = {0,-1,0,1,0};
    long long ans = 0, mod = 7 + 1e9;
    
    long long dp[1001][1001];
    
    long long  solve(int x,int y,int m,int n,vector<vector<int>> &grid){
        if(dp[x][y] != -1){
            return dp[x][y];
        }
        
        long long a = 1;
        for(long long i = 0; i < 4; i++){
            long long nx = x + dir[i], ny = y + dir[i + 1];
            if(nx >= 0 and nx < m and ny >= 0 and ny < n and grid[nx][ny] > grid[x][y]){
                a = (a + (solve(nx,ny,m,n,grid) % mod)) % mod;
            }
        }
    
        return dp[x][y] = a % mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        long long m = grid.size(), n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = (ans + (solve(i,j,m,n,grid) % mod) % mod);
            }
        }
        return ans % mod;
    }
};