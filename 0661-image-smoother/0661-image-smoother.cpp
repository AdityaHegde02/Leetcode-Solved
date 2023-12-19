class Solution {
public:
    vector<pair<int,int>> dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> ans(m,vector<int> (n,0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                int sum = img[i][j];
                int cnt = 1;
                for(auto &k : dir){
                    int x = i +  k.first, y = j + k.second;
                    if(x >= 0 and x < m and y >= 0 and y < n){
                        cnt++;
                        sum += img[x][y];
                    }
                }
                ans[i][j] = (sum/cnt);
            }
        }
        
        return ans;
    }
};