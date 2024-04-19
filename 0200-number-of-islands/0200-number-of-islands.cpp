class Solution {
public:
    void dfs(vector<vector<char>> &grid,int x,int y,vector<vector<int>> &dir){
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<dir.size();i++){
            int x1 = x + dir[i][0] ;
            int y1 = y + dir[i][1] ;
            if( x1 >= 0  and x1 < m and y1 >=0 and y1 < n and grid[x1][y1]=='1'){
                grid[x1][y1] = '2';
                dfs(grid,x1,y1,dir);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0 ;
        
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    grid[i][j] = '2';
                    dfs(grid,i,j,dir);
                    islands ++;
                }
            }
        }
        
        return islands;
    }
};