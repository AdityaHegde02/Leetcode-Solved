class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0 ;
        for(int i=0;i<n;i++){               // for every row
            for(int j=0;j<n;j++){           // for every column
                bool f = 0 ;
                for(int k=0;k<n;k++){     // for all values in that row and column
                    if(grid[i][k]!=grid[k][j]){
                        f=1;
                        break;
                    }
                }
                if(!f){
                    count++;
                }
            }
        }
        return count;
    }
};