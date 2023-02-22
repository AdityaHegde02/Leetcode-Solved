class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int i1 = lower_bound(nums.begin(),nums.end(),0) - nums.begin();
        if(i1 >= n){
            return n;
        }
        int z = 0;
        if(nums[i1] == 0){
            while(i1 < n and nums[i1] == 0){
                z++;
                i1++;
            }
        }
        return max(i1 - z,n - i1);
    }
};