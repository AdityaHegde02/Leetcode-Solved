class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size();
        int rem = grid[0][0] % x;
        vector<int> uni;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] % x != rem){
                    return -1;
                }
                else{
                    uni.push_back(grid[i][j]);
                }
            }
        }
        sort(uni.begin(),uni.end());
        int med = uni[(m*n)/2],ans = 0;
        for(int i = 0; i < m*n; i++){
            ans += (abs(med-uni[i]))/x;
        }
        return ans;
    }
};