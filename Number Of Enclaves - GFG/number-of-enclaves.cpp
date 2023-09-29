//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> dir = {0,-1,0,1,0};
    
    void dfs(int i,int j,int n,int m,vector<vector<int>> &mat){
        mat[i][j] = 0;
        
        for(int a = 0; a < 4; a++){
            int ni = i + dir[a], nj = j + dir[a + 1];
            if(ni >= 0 and ni < n and nj >= 0 and nj < m and mat[ni][nj] == 1){
                dfs(ni,nj,n,m,mat);
            }
        }
    }
    
    int numberOfEnclaves(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++){
            if(mat[i][0] == 1){
                dfs(i,0,n,m,mat);
            }
            if(mat[i][m - 1] == 1){
                dfs(i,m - 1,n,m,mat);
            }
        }
       
        for(int i = 0; i < m; i++){
            if(mat[0][i] == 1){
                dfs(0,i,n,m,mat);
            }
            if(mat[n - 1][i] == 1){
                dfs(n - 1,i,n,m,mat);
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans += (mat[i][j]);
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends