class Solution {
public:
    int subsetSum(int n,int find,vector<int> &nums,vector<vector<int>> &dp){
        if(n == 0){
            if(find == 0){
                return 1;
            }
            return 0;
        }
        
        if(dp[n - 1][find] != -1){
            return dp[n -1][find];
        }
        
        if(nums[n - 1] <= find){
            return dp[n - 1][find] = subsetSum(n - 1,find - nums[n - 1],nums,dp) + subsetSum(n - 1,find,nums,dp);
        }
        
        return dp[n - 1][find] = subsetSum(n - 1,find,nums,dp);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if((sum - target) % 2 or (sum < target)){
            return 0;
        }
        int find = (sum - target)/2;
        vector<vector<int>> dp(n + 1,vector<int> (find + 1,-1));
        return subsetSum(n,find,nums,dp);
    }
};