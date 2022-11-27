class Solution {
public:
    vector<int> dx = {0,-1,0,1};
    vector<int> dy = {-1,0,1,0};
    
    bool check(int i,int j,int m,int n,int& f,vector<vector<int>>& grid1,vector<vector<int>>& grid2){
        if(i < 0 or i >= m or j < 0 or j >= n or grid2[i][j] == 0){
            return 0;
        }
        
        if(grid1[i][j] == 0){
            f = 0;
        }
        
        grid2[i][j] = 0;
        
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            check(ni,nj,m,n,f,grid1,grid2);
        }
        
        return f;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int subIslands = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j]){
                    int f = 1;
                    check(i,j,m,n,f,grid1,grid2);
                    subIslands += (f==1);
                }
            }
        }
        return subIslands;
    }
};