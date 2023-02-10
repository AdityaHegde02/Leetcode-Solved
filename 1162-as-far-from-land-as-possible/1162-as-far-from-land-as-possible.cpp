class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), water = 0, land = 0;
        vector<int> dir = {0,-1,0,1,0};
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    q.push({i,j});
                    land++;
                }
                else{
                    water++;
                }
            }
        }
        
        if(land == 0 or water == 0){
            return -1;
        }
        
        int level = -1;
        
        while(!q.empty()){
            int sz = q.size();
            level++;
            for(int i = 0; i < sz; i++){
                auto top = q.front();
                int x = top.first, y = top.second;
                q.pop();
                for(int j = 0; j < 4; j++){
                    int nx = x + dir[j], ny = y + dir[j + 1];
                    if(nx >= 0 and nx < n and ny >= 0 and ny < n and !grid[nx][ny]){
                        grid[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        
        return level;
    }
};