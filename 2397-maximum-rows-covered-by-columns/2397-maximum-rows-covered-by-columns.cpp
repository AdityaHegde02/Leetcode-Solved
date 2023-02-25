class Solution {
public:
    int mx = 0;
    
    void solve(int col,int m,int n,vector<vector<int>> &matrix,int numSelect){
        if(col >= n){
            if(numSelect == 0){
                int rows = 0;
                for(int i = 0; i < m; i++){
                    bool f = 1;
                    for(int j = 0; j < n; j++){
                        if(matrix[i][j]){
                            f = 0;
                            break;
                        }
                    }
                    if(f){
                        rows++;
                    }
                }
                mx = max(mx,rows);
            }
            return ;
        }
        
        vector<vector<int>> copy = matrix;
        
        if(numSelect){
            for(int i = 0; i < m; i++){
                matrix[i][col] = 0;
            }
            
            solve(col + 1,m,n,matrix,numSelect - 1);
        }
        
        matrix = copy;
        solve(col + 1,m,n,matrix,numSelect);
    }
    
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size();
        solve(0,m,n,matrix,numSelect);
        return mx;
    }
};