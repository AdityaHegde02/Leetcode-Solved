class Solution {
public:
    vector<int> dir = {0,-1,0,1,0};
    
    int solve(int x,int y,int m,int n,vector<vector<int>> &grid){
        if(x < 0 or x >= m or y < 0 or y >= n or !grid[x][y]){
            return 0;
        }    
        
        int sum = grid[x][y];
        grid[x][y] = 0;
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i], ny = y + dir[i + 1];
            sum += solve(nx,ny,m,n,grid);
        }
        
        return sum;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    int x = solve(i,j,m,n,grid);
                    ans = max(ans,x);
                }
            }
        }
        return ans;
    }
};