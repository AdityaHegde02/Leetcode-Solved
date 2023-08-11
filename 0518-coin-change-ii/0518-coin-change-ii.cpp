class Solution {
public:
    int coinChange(int n,int amount,vector<int> &coins,vector<vector<int>> &dp){
        if(amount == 0){
            return 1;
        }
        if(n == 0){
            return 0;
        }

        if(dp[n-1][amount] != -1){
            return dp[n-1][amount];
        }

        if(coins[n-1] <= amount){
            return dp[n-1][amount] =  (coinChange(n,amount-coins[n-1],coins,dp) + coinChange(n-1,amount,coins,dp));
        }

        return dp[n-1][amount] = coinChange(n-1,amount,coins,dp);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
        return coinChange(n,amount,coins,dp);
    }
};