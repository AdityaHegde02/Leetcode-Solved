class Solution {
public:
    vector<int> dir = {0,-1,0,1,0};
    
    void pushInQ(int x,int y,int n,queue<pair<int,int>> &q,vector<vector<int>> &grid){ 
        grid[x][y] = -1;
        q.push({x,y});
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i], ny = y + dir[i + 1];
            if(nx < 0 or nx >= n or  ny < 0 or ny >= n or grid[nx][ny] != 1){
                continue;
            }
            pushInQ(nx,ny,n,q,grid);
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        int found = 0;
        for(int i = 0; i < n and !found; i++){
            for(int j = 0; j < n and !found; j++){
                if(grid[i][j]){
                    pushInQ(i,j,n,q,grid);
                    found = 1;
                }
            }
        }
        
        int level = 0;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto top = q.front();
                q.pop();
                int x = top.first, y = top.second;
                for(int j = 0; j < 4; j++){
                    int nx = x + dir[j], ny = y + dir[j + 1];
                    if(nx >= 0 and nx < n and ny >= 0 and ny < n){
                        if(grid[nx][ny] == 1){
                            return level;
                        }
                        if(grid[nx][ny] == 0){
                            q.push({nx,ny});
                            grid[nx][ny] = -1;
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};