class Solution {
public:
    vector<vector<int>> dir{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    
    bool isSafe(int x,int y,int m,int n){
        if(x < 0 or x >= m or y < 0 or y >= n){
            return false;
        }
        return true;
    }
    
    int count(vector<vector<int>>& board,int x,int y,int m , int n){
        int c = 0;
        for(int i = 0 ; i < 8 ; i++){
            if( isSafe(x + dir[i][0],y + dir[i][1],m ,n)){
                if(board[x + dir[i][0]][y + dir[i][1]]){
                    c++;
                }
            }
        }
        return c;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> copy = board;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int state = board[i][j];
                int liveNeighbours = count(copy,i,j,m ,n);
                if(state == 0){
                    if(liveNeighbours == 3){
                        board[i][j] = 1;
                    }
                }
                else{
                    if(liveNeighbours < 2 or liveNeighbours > 3){
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
};