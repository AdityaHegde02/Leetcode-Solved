class Solution {
public:
    int dp[5001][2];
    
    int solve(int i,int n,vector<int> &prices,int canBuy){
        if(i >= n){
            return 0;
        }
        
        if(dp[i][canBuy] != -1){
            return dp[i][canBuy];
        }
        
        int take = 0, skip = 0;
        if(canBuy){
            take -= prices[i];
            take += solve(i + 1,n,prices,0);
            skip += solve(i + 1,n,prices,1);
        }
        else{
            take += prices[i];
            take += solve(i + 2,n,prices,1);
            skip += solve(i + 1,n,prices,0);
        }
        
        return dp[i][canBuy] = max(take,skip);
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,n,prices,1);
    }
};