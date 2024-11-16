class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int last_break = -1;
        for(int i = 0; i < n; i++){
            if( (i >= k - 1)){
                if(last_break < (i - k + 1)){
                    ans.push_back(nums[i]);
                }
                else{
                    ans.push_back(-1);
                }
            }
            if(i + 1 < n and nums[i]  + 1 != nums[i + 1]){
                last_break = i;
            }
        }
        return ans;
    }
};