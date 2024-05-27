class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int mx = nums[n-1];
        for(int i = 0; i <= mx; i++){
            int idx = lower_bound(nums.begin(),nums.end(),i) - nums.begin();
            if(idx < n){
                if((n - idx) == i){
                    return i;
                }
            }
        }
        return -1;
    }
};