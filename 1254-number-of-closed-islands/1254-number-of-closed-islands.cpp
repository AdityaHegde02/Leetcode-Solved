class Solution {
public:
    vector<int> dir = {0,-1,0,1,0};

    int bfs(int i,int j,int m,int n,vector<vector<int>> &grid){
        queue<vector<int>> q;
        q.push({i,j});
        grid[i][j] = -1;
        int status = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int a = 0; a < sz; a++){
                vector<int> top = q.front();
                q.pop();
                int x = top[0];
                int y = top[1];
                if(x == 0 or x == m - 1 or y == 0 or y == n - 1){
                    status = 0;
                }
                for(int b = 0; b < 4; b++){
                    int c = x + dir[b];
                    int d = y + dir[b + 1];
                    if(c >= 0 and c < m and d >= 0 and d < n and grid[c][d] == 0){
                        vector<int> o = {c,d};
                        q.push(o);
                        grid[c][d] = -1;
                    }
                }
            }
        }
        return status;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int closed = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    closed += bfs(i,j,m,n,grid);
                }
            }
        }
        return closed;
    }
};