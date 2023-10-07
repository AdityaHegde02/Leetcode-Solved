class Solution {
public:
    int mod = 7 + 1e9;
    int dp[52][52][102];
    
    int solve(int n,int k,int prev,int m){
        if(n <= 0){
            return (k == 0);
        }
        
        if(k < 0){
            return 0;
        }
        
        if(dp[n][k][prev] != -1){
            return dp[n][k][prev];
        }
        
        int ways = 0;
        for(int i = 1; i <= m; i++){
            if(i > prev)
                ways = (ways + solve(n - 1,k - 1, i, m)) % mod;
            else
                ways = (ways + solve(n - 1,k, prev, m)) % mod;    
        }
        
        return dp[n][k][prev] = ways % mod;
    }
    
    int numOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,0,m);
    }
};