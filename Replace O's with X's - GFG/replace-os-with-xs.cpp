//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> dir = {0,-1,0,1,0};
    
    void dfs(int i,int j,int n,int m,vector<vector<char>> &mat){
        mat[i][j] = 'A';
        
        for(int a = 0; a < 4; a++){
            int ni = i + dir[a], nj = j + dir[a + 1];
            if(ni >= 0 and ni < n and nj >= 0 and nj < m and mat[ni][nj] == 'O'){
                dfs(ni,nj,n,m,mat);
            }
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i = 0; i < n; i++){
            if(mat[i][0] == 'O'){
                dfs(i,0,n,m,mat);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(mat[i][m - 1] == 'O'){
                dfs(i,m - 1,n,m,mat);
            }
        }
        
        for(int i = 0; i < m; i++){
            if(mat[0][i] == 'O'){
                dfs(0,i,n,m,mat);
            }
        }
        
        for(int i = 0; i < m; i++){
            if(mat[n - 1][i] == 'O'){
                dfs(n - 1,i,n,m,mat);
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 'A'){
                    mat[i][j] = 'O';
                }
                else{
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends