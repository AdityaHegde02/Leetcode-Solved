class Solution {
public:
    vector<int> dir = {0,1,0};
    void dfs(int i,int j,int m,int n,vector<vector<char>>& board){
        if(i < 0 or i >= m or j < 0 or j >= n or board[i][j] == '.'){
            return ;
        }
        
        board[i][j] = '.';
        for(int d = 0; d < 2; d++){
            int ni = i + dir[d], nj = j + dir[d + 1];
            dfs(ni,nj,m,n,board);
        }
    }
    
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), battleShips = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'X'){
                    dfs(i,j,m,n,board);
                    battleShips++;
                }
            }
        }
        return battleShips;
    }
};