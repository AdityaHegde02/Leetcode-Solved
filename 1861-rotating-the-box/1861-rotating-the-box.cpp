class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        for(int i = m - 1; i >= 0; i--){
            int j = n - 1;
            while(j >= 0){
                int stones = 0, lastStart = j;
                while(j >= 0 and box[i][j] != '*'){
                    stones += (box[i][j] == '#');
                    box[i][j] = '.';
                    j--;
                }
                
                for(int k = lastStart; k > j and stones; k--){
                    box[i][k] = '#';
                    stones--;
                }
                j--;
                
            }
        }
        
        // return box;
        
        vector<vector<char>> ans(n,vector<char> (m,'.'));
        for(int i = m - 1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                ans[j][m - i - 1] = box[i][j];
            }
        }
            
        return ans;
    }
};
