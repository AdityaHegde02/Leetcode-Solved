class Solution {
public:
    int dp[100001][3][2];
    
    int solve(int i,int k,bool buy,vector<int> &p){
        if(i >= p.size()){
            return 0;
        }    
        
        if(k == 0){
            return 0;
        }
        
        if(dp[i][k][buy] != -1){
            return dp[i][k][buy];
        }
        
        int ans = 0;
        // if buy
        if(buy){
            // take
            int take = solve(i + 1,k,!buy,p) - p[i];
            
            // dont take
            int notake = solve(i + 1,k,buy,p);
            
            ans = max(take,notake);
        }
        else{
            // sell
            int sell = solve(i + 1,k - 1,!buy,p) + p[i];
            
            // dont sell
            int nosell = solve(i + 1,k,buy,p);
            
            ans = max(sell,nosell);
        }
        
        return dp[i][k][buy] = ans;
    }
    
    int maxProfit(vector<int>& p) {
        int k = 2;
        int n = p.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,k,1,p);
    }
};