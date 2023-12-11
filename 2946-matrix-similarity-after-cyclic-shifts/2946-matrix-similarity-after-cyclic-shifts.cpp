class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k = (k % n);
        vector<vector<int>> l = mat;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i % 2 == 0){
                    l[i][j] = mat[i][(j + k) % n];
                }
                else{
                    l[i][j] = mat[i][(j - k + n) % n];
                }
            }
        }
        return (l == mat);
    }
};