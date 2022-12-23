class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        int dp[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = 0;
            }
        }
        for(int len = 1; len < n - 1; len++){
            for(int start = 1; start < n - len; start++){
                int end = (start + len - 1);
                for(int k = start; k <= end; k++){     //including k atlast
                    dp[start][end] = max(dp[start][end],dp[start][k-1] + dp[k + 1][end] + nums[start - 1]*nums[end + 1]*nums[k]);
                }
            }
        }
        return dp[1][n - 2];
    }
}; 