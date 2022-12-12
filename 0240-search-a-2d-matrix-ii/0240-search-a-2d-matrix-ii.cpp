class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int x = 0, y = n - 1;
        while(true){
            if(x < 0 or y < 0 or x >= m or y >= n){
                return false;
            }
            if(target == mat[x][y]){
                return true;
            }
            else if(target < mat[x][y]){
                y--;
            }
            else{
                x++;
            }
        }
        return false;
    }
};