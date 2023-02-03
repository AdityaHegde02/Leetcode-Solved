class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<char>> copy = board;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int> (n,0));
        vector<int> dir = {0,-1,0,1,0};
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O' and (i == 0 or i == m -  1 or j == 0 or j == n - 1)){
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto top = q.front();
                q.pop();
                int x = top.first;
                int y = top.second;
                copy[x][y] = 'A';
                vis[x][y] = 1;
                for(int j = 0; j < 4; j++){
                    int X = x + dir[j];
                    int Y = y + dir[j + 1];
                    if(X >= 0 and X < m and Y >= 0 and Y < n and board[X][Y] == 'O' and !vis[X][Y]){
                        q.push({X,Y});
                    }
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(copy[i][j] != 'A'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};