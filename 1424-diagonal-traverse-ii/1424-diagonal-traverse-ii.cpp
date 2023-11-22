class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        
        unordered_map<int,vector<int>> mp;
        
        int maxKey = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            for( int j = 0 ; j < nums[i].size() ; j++){
                maxKey = max(maxKey,i+j);
                mp[i+j].push_back(nums[i][j]);
            }
        }
        
        for( int i = 0 ; i <= maxKey ; i++ ){
            int len = mp[i].size();
            for( int j = len - 1 ; j >= 0 ; j-- ){
                ans.push_back(mp[i][j]);
            }
        }
        
        return ans;
    }
};