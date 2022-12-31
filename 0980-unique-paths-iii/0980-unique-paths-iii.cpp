class Solution {
public:
    int solve(vector<vector<int>>& grid,int zero,int i, int j, int n, int m){
        
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j]==-1 )
            return 0;
        
        if(grid[i][j]==2){
            if(zero==-1)
                return 1;
            else
                return 0;
        }
            
        grid[i][j]=-1; 
        zero--;
        
        int l=solve(grid,zero,i,j-1,n,m);
        int r=solve(grid,zero,i,j+1,n,m);
        int u=solve(grid,zero,i-1,j,n,m);
        int d=solve(grid,zero,i+1,j,n,m);
        
        // bactrack
        grid[i][j]=0;
        zero++;
        
        return l+r+u+d;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int startRow=0,startCol=0;
        int zero=0;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)  zero++;
                
                if(grid[i][j]==1){
                    startRow=i;
                    startCol=j;
                }
            }
        }
        
        return solve(grid,zero,startRow,startCol,n,m);

    }
};
