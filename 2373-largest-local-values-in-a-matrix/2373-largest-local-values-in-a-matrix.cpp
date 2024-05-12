class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans;
        int n = grid.size();
        int total = (n-2)*(n-2);
        for(int i=0;i<n-2;i++){
            vector<int> a;
            for(int j=0;j<n-2;j++){
                int mx = 0;
                for(int k = i ; k<i+3 ;k++){
                    for(int l = j;l<j+3;l++){
                        mx = max(mx,grid[k][l]);
                    }
                }
                a.push_back(mx);
            }
            ans.push_back(a);
        }
        return ans;
    }
};