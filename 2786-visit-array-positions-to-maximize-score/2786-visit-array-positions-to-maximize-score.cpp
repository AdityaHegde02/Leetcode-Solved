class Solution {
public:
    long long solve(int i,int rem,vector<int>& nums, int x,vector<vector<long long>> &dp){
        if(i >= nums.size()){
            return 0;
        }    
        
        if(dp[i][rem] != -1){
            return dp[i][rem];
        }
        
        long long take = 0, nottake = 0;
        // not take
        nottake += (long long)solve(i + 1,rem,nums,x,dp);
        
        // take
        if(nums[i] % 2 == rem){
            take += (long long)(nums[i] + nottake);
        }
        else{
            take += (long long)(nums[i] + solve(i + 1,!rem,nums,x,dp) - x);
        }
        
        return dp[i][rem] = max(take,nottake);
    }
    
    long long maxScore(vector<int>& nums, int x) {
        vector<vector<long long>> dp(nums.size() + 1,vector<long long> (2,-1));
        return (long long)(nums[0] + solve(1,nums[0] % 2,nums,x,dp));
    }
};