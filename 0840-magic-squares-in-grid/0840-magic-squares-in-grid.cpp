class Solution {
public:
    bool sumsSame(int x,int y,vector<vector<int>> &grid){
        int S = -1;
        unordered_set<int> st;
        
        for(int i = x; i < x + 3; i++){
            int rowSum = 0;
            for(int j = y; j < y + 3; j++){
                rowSum += grid[i][j];
                st.insert(grid[i][j]);
                if(grid[i][j] >= 10 or grid[i][j] == 0){
                    return false;
                }
            }
            if(S == -1){
                S = rowSum;
            }
            else if(S != rowSum){
                return false;
            }
        }
        
        if(st.size() != 9){
            return false;
        }
        
        for(int i = y; i < y + 3; i++){
            int colSum = 0;
            for(int j = x; j < x + 3; j++){
                colSum += grid[j][i];
            }
            if(S != colSum){
                return false;
            }
        }
        
        int d1 = grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2];
        int d2 = grid[x + 2][y] + grid[x + 1][y + 1] + grid[x][y + 2];
        if(d1 != S || d2 != S){
            return false;
        }
        return true;
    }
    
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), magic = 0;
        for(int i = 0; i < m - 2; i++){
            for(int j = 0; j < n - 2; j++){
                // 3*3 sub-matrix starting with this
                if(sumsSame(i,j,grid)){
                    magic++;
                }
            }
        }
        return magic;
    }
};