class Solution {
public:
    int mod = 7 + 1e9;
    
    long long solve(int i,int sum,int n,int x,vector<vector<int>> &dp){
        if(sum < 0){
            return 0;
        }
        
        if(sum == 0){
            return 1;
        }
        
        if(i > n){
            return 0;
        }
        
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        
        long long int ans = 0;
        // take
        if(sum >= pow(i,x))
            ans = (ans + solve(i + 1,sum - pow(i,x),n,x,dp) % mod);
        
        // not take
        ans = (ans + solve(i + 1,sum,n,x,dp) % mod);
        
        return dp[i][sum] = ans % mod;
    }
    
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1,vector<int> (n + 1,-1));
        return solve(1,n,n,x,dp) % mod;
    }
};