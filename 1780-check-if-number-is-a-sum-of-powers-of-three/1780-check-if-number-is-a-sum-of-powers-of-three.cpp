class Solution {
public:
    bool solve(int power,int n,vector<vector<bool>> &dp){
        if(n <= 0 or power > 14){
            return (n == 0);
        }    
        
        if(dp[power][n]){
            return true;
        }
        
        return dp[power][n] = (solve(power + 1,n - pow(3,power),dp) || solve(power + 1,n,dp));
    }
    
    bool checkPowersOfThree(int n) {
        vector<vector<bool>> dp(16,vector<bool> (n + 1,false));
        return solve(0,n,dp);
    }
};