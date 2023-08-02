class Solution {
public:
    vector<int> dir = {0,-1,0,1,0};         // 4 directions
    
    int getLongestPath(int i,int j,int m,int n,vector<vector<int>> &a,vector<vector<int>> &vis){
        if(vis[i][j] > 0){
            return vis[i][j];               // If its already computed
        }
        
        int mx = 0;                        // total mx for this tile now 
        for(int d = 0; d < 4; d++){
            int nx = i + dir[d], ny = j + dir[d + 1];
            if(nx >= 0 and nx < m and ny >= 0 and ny < n){
                if(a[nx][ny] > a[i][j]){
                    mx = max(mx,getLongestPath(nx,ny,m,n,a,vis));
                }
            }
        }
        
        vis[i][j] = 1 + mx;
        return vis[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& a) {
        int m = a.size(),n = a[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j]){
                    ans = max(ans,getLongestPath(i,j,m,n,a,vis));
                }
            }
        }
      
        return ans;
    }
};