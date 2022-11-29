class Solution {
public:
    int dp[202][10002];
    
    bool subsetSum(int n,vector<int> &nums,int target){
        if(target == 0){
            return true;
        }
        
        if(n <= 0 or target < 0){
            return false;
        }
        
        if(dp[n - 1][target] != -1){
            return dp[n - 1][target];
        }
        
        if(nums[n - 1] <= target){
            return dp[n - 1][target] = (subsetSum(n-1,nums,target - nums[n - 1])) or (subsetSum(n - 1,nums,target));
        }
        
        return dp[n - 1][target] = subsetSum(n - 1,nums,target);
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int &i : nums){
            totalSum += i;
        }
        
        if(totalSum % 2){
            return false;
        }
        
        int target = (totalSum)/2;
        memset(dp,-1,sizeof(dp));
        
        return subsetSum(nums.size(),nums,target);
    }
};