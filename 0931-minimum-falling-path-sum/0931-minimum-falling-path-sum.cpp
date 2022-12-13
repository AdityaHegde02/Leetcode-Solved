class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n,vector<int> (n));
        for(int i = 0; i < n; i++){
            dp[0][i] = mat[0][i];
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == 0){
                    dp[i][j] = mat[i][j] + min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j == n - 1){
                    dp[i][j] = mat[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                }
                else{
                    dp[i][j] = mat[i][j] + min({dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]});
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }
};