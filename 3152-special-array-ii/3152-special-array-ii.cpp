class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> fail;
        for(int i = 0; i < nums.size() - 1; i++){
            if((nums[i] % 2) == (nums[i + 1] % 2)){
                fail.push_back(i);
            }
        }
        
        for(int i = 0; i < queries.size(); i++){
            int s = queries[i][0], e = queries[i][1] - 1;
            int idx = lower_bound(fail.begin(),fail.end(),s) - fail.begin();
            for(int j = idx; j < fail.size(); j++){
                if(fail[j] <= e){
                    ans.push_back(0);
                    break;
                }
            }
            if(ans.size() != i + 1){
                ans.push_back(1);
            }
        }
        return ans;
    }
};