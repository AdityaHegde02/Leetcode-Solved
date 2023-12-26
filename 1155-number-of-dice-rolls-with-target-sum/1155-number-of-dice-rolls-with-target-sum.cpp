class Solution {
public:
    int mod = 7 + 1e9;
    int dp[31][1001];
    
    int solve(int i,int n,int k,int target){
        if(i > n){
            return (target == 0);
        }
        
        if(target < 0){
            return 0;
        }
        
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        
        int ways = 0;
        for(int d = 1; d <= k; d++){
            if(d <= target){
                ways = (ways + solve(i + 1,n,k,target - d)) % mod;
            }
        }
        
        return dp[i][target] = ways % mod;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n,k,target) % mod;
    }
};