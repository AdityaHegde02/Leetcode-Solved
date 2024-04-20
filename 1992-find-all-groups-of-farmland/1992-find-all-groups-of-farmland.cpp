class Solution {
public:
    int findy(int i,int j,int m,int n,vector<vector<int>>& land){
        if(j >= n or land[i][j] == 0){
            return j - 1;
        }

        return findy(i,j + 1,m,n,land);
    }
    
    int findx(int i,int j,int m,int n,vector<vector<int>>& land){
        if(i >= m or land[i][j] == 0){
            return i - 1;
        }

        return findx(i + 1,j,m,n,land);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> visited(m,vector<int> (n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(land[i][j] == 1 and visited[i][j] == 0){
                    int y = findy(i,j,m,n,land);
                    int x = findx(i,j,m,n,land);
                    for(int a = i; a <= x; a++){
                        for(int b = j; b <= y; b++){
                            visited[a][b] = 1;
                        }
                    }
                    ans.push_back({i,j,x,y});
                }
            }
        }
        return ans;
    }
};