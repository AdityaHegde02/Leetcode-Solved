class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dir = {0,-1,0,1,0};
        vector<vector<vector<bool>>> vis(m+1,vector<vector<bool>> (n+1,vector<bool> (k+1,false)));
        int steps = 0;
        queue<vector<int>> q;
        q.push({0,0,k});
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto top = q.front();
                q.pop();
                int x = top[0];
                int y = top[1];
                int obs = top[2];
                if(x == m - 1 and y == n - 1){
                    return steps;
                }
                for(int j = 0;j < 4; j++){
                    int nx = x + dir[j];
                    int ny = y + dir[j+1];
                    if(nx >= 0 and ny >= 0 and nx < m and ny < n){
                        if(grid[nx][ny] == 0 and !vis[nx][ny][obs]){
                            vis[nx][ny][obs] = 1;
                            q.push({nx,ny,obs});
                        }
                        if(grid[nx][ny] == 1 and obs and !vis[nx][ny][obs-1]){
                            q.push({nx,ny,obs-1});
                            vis[nx][ny][obs-1] = 1;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};