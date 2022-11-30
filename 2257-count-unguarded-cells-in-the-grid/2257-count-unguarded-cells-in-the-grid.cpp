class Solution {
public:
    int count(int x,int y,int m,int n,vector<vector<int>> &visited){
        int ans = 0;
        int i = x,j = y;
        y--;
        while(y >= 0){       //left
            if(visited[x][y] == 0){
                visited[x][y] = 1;
                ans++;
                y--;
            }
            else if(visited[x][y] == 1){
                y--;
            }
            else{
                break;
            }
        }
        x = i,y = j;
        x--;
        while(x >= 0){       //up
            if(visited[x][y] == 0){
                visited[x][y] = 1;
                ans++;
                x--;
            }
            else if(visited[x][y] == 1){
                x--;
            }
            else{
                break;
            }
        }
        x = i,y = j;
        y++;
        while(y < n){        //right
            if(visited[x][y] == 0){
                visited[x][y] = 1;
                ans++;
                y++;
            }
            else if(visited[x][y] == 1){
                y++;
            }
            else{
                break;
            }
        }
        x = i,y = j;
        x++;
        while(x < m){        //down
            if(visited[x][y] == 0){
                visited[x][y] = 1;
                ans++;
                x++;
            }
            else if(visited[x][y] == 1){
                x++;
            }
            else{
                break;
            }
        }
        return ans;
    }
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int G = guards.size();
        int W = walls.size();
        
        int total = (m*n);
        int bad = 0;
        
        vector<vector<int>> visited(m,vector<int> (n,0));
        
        for(int i = 0; i < G; i++){
            visited[guards[i][0]][guards[i][1]] = 10;
        }
        
        for(int i = 0; i < W; i++){
            visited[walls[i][0]][walls[i][1]] = 5;
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == 10){
                    bad += count(i,j,m,n,visited);
                }
            }
        }
        return (total - bad - W - G);
    }
};