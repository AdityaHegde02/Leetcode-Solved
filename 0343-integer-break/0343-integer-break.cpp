class Solution {
public:
    int dp[59][59];
    
    int solve(int n,int took){
        if(n < 0){
            return 0;
        }    
        
        if(n == 0){
            return (took > 1);
        }
        
        if(dp[n][took] != -1){
            return dp[n][took];
        }
        
        int product = 1;
        
        for(int i = 1; i <= n; i++){
            int p = solve(n - i,took + 1);
            product = max(product,p*i);
        }
        
        return dp[n][took] = product;
    }
    
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,0);
    }
};