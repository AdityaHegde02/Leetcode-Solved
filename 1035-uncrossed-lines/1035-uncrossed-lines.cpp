class Solution {
public:
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>> &dp){
        if(i >= nums1.size() or j >= nums2.size()){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int inc = 0,exc = 0;
        if(nums1[i] == nums2[j]){
            inc = 1 + solve(i + 1,j + 1,nums1,nums2,dp);
        }
       
        exc = max(solve(i,j + 1,nums1,nums2,dp),solve(i + 1,j,nums1,nums2,dp));
        
        return dp[i][j] = max(inc,exc);
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<vector<int>> dp(m + 1,vector<int> (n + 1,-1));
        return solve(0,0,nums1,nums2,dp);
    }
};