class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 0){
                for(int j = 0; j < n; j++){
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        
        for(int j = 1; j < n; j++){
            int z = 0;
            for(int i = 0; i < m; i++){
                z += (grid[i][j] == 0);
            }
            if(z > (m/2)){
                for(int k = 0; k < m; k++){
                    grid[k][j] = !grid[k][j];
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans += pow(2,n - j - 1)*grid[i][j];
            }
        }
        
        return ans;
    }
};