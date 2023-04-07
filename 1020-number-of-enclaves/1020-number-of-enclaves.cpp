class Solution {
public:
    vector<int> dir = {0,-1,0,1,0};

    int dfs(int i,int j,int m,int n,vector<vector<int>> &grid){
        if(i < 0 or i >= m or j < 0 or j >= n or grid[i][j] != 1){
            return 0;
        }

        int count = 1;
        grid[i][j] = -1;
        for(int k = 0; k < 4; k++){
            int x = i + dir[k],y = j + dir[k + 1];
            if(x < 0 or x >= m or y < 0 or y >= n or grid[x][y] != 1){
            continue;
        }
            count += dfs(x,y,m,n,grid);
        }
        return count;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 or i == m - 1 or j == 0 or j == n - 1 and grid[i][j] == 1){
                    dfs(i,j,m,n,grid);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    ans += dfs(i,j,m,n,grid);
                }
            }
        }

        return ans;
    }
};