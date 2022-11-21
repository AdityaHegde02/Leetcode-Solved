class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long total = accumulate(nums.begin(),nums.end(),0LL);
        int splits = 0;
        long long leftSum = 0;
        for(int i = 0; i < n - 1; i++){
            leftSum += nums[i];
            total -= nums[i];
            if(leftSum >= total){
                splits++;
            }
        }
        return splits;
    }
};