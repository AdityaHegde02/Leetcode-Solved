class Solution {
public:
    int mod = 7 + 1e9;
    int dp[100001];
    
    int solve(int low,int high,int zero,int one,int sz){
        if(sz > high){
            return 0;
        }
        
        if(dp[sz] != -1){
            return dp[sz];
        }
        
        int ans = 0;
        if(sz >= low and sz <= high){
            ans++;
        }
        
        // zero
        ans += solve(low,high,zero,one,sz + zero) % mod;
        
        // one
        ans += solve(low,high,zero,one,sz + one) % mod;
        return dp[sz] = (ans % mod);
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        return solve(low,high,zero,one,0);
    }
};