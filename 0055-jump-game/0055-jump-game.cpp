class Solution {
public:
    int dp[100001];

    bool solve(int i,int n,vector<int> &nums){
        if(i >= n - 1){
            return true;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        
        for(int j = 1; j <= nums[i]; j++){
            bool f = solve(i + j,n,nums);
            if(f){
                return true;
            }
        }
        
        return dp[i] = false;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,nums);
    }
};