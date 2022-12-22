class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mx = INT_MIN;
        for(int i = 0; i < m - 2; i++){
            for(int j = 0; j < n - 2; j++){
                int x = 0;
                x += (grid[i][j] + grid[i][j+1] + grid[i][j + 2] + grid[i+1][j+1] + grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2]);
                mx = max(x,mx);
                
            }
        }
        return mx;
    }
};