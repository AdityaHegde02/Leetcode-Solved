class Solution {
public:
    int dp[101];
    int solve(int i,vector<int> &a){
        if(i < 0){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        return dp[i] = max(a[i] + solve(i-2,a),solve(i-1,a));
    }
        
    int rob(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < 101; i++){
            dp[i] = -1;
        }
        if(n==1){
            return nums[0];
        }
        int f = solve(n-1,nums);
        return f;
    }
};