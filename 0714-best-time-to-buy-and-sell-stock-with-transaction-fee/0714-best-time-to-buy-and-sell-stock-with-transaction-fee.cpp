class Solution {
public:
    int solve(int idx,int buy,int fee,vector<int> &prices,vector<vector<int>> &dp){
        int n = prices.size();
        if(idx >= n){
            return 0;
        }    
        
        if(dp[idx][buy] != -1){
            return  dp[idx][buy];
        }
        
        if(buy == 1){
            int take = 0, notTake = 0;
            take = -prices[idx] + solve(idx + 1,0,fee,prices,dp);
            notTake = solve(idx + 1,1,fee,prices,dp);
            return dp[idx][buy] = max(take,notTake);
        }
        else{
            int sell = 0, notSell = 0;
            sell = (prices[idx] - fee) + solve(idx + 1,1,fee,prices,dp);
            notSell = solve(idx + 1,0,fee,prices,dp);
            
            return dp[idx][buy] = max(sell,notSell);
        }
        
        return 0;
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int mx = *max_element(prices.begin(),prices.end());
        vector<vector<int>> dp(n + 1,vector<int> (2,-1));
        return solve(0,1,fee,prices,dp);
    }
};