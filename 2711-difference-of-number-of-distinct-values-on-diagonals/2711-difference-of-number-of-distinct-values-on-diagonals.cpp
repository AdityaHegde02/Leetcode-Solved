class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m,vector<int> (n,0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                unordered_set<int> a,b;
                for(int k = 0; k < i; ++k){
                    for(int l = 0; l < j; ++l){
                        if(i - k == j - l){
                            a.insert(grid[k][l]);
                        }
                    }
                }
                
                for(int k = i + 1; k < m; ++k){
                    for(int l = j + 1; l < n; ++l){
                        if(i - k == j - l){
                            b.insert(grid[k][l]);
                        }
                    }
                }
                
                int x = a.size(),y = b.size();
                ans[i][j] = abs(x - y);
            }
        }
        
        return ans;
    }
};