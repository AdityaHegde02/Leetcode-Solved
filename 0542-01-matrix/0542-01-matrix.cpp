class Solution {
public:
    vector<int> dir = {0,-1,0,1,0};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dis(m,vector<int> (n,INT_MAX));
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto x = q.front().first, y = q.front().second;
                q.pop();
                for(int j = 0; j < 4; j++){
                    int nx = x + dir[j], ny = y + dir[j + 1];
                    if(nx >= 0 and nx < m and ny >= 0 and ny < n and dis[nx][ny] > dis[x][y] + 1){
                        q.push({nx,ny});
                        dis[nx][ny] = 1 + dis[x][y];
                    }
                }
            }
        }
        
        return dis;
    }
};