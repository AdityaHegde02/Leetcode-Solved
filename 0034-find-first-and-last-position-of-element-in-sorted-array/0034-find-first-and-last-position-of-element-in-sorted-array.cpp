class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0)
            return {-1,-1};
        int start = -1;
        int end = -1;
        int lowidx = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int highidx = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if( lowidx<n and nums[lowidx]==target ){
            start = lowidx;
        }
        if( highidx and highidx-1<n and nums[highidx-1]==target ){
            end = highidx-1;
        }
        return {start,end};
    }
};