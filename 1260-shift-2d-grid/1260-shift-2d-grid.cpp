class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m,vector<int> (n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int nx = (i + (j + k)/n) % m;
                int ny = (j + k) % n;
                ans[nx][ny] = grid[i][j];
            }
        }
        return ans;
    }
};