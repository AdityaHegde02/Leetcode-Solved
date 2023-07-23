class Solution {
public:
    int mod = 7 + 1e9;
    long long dp[51][1001];
    
    long long solve(int i,long long target,vector<vector<int>>& types){
        if(target <= 0){
            return (target == 0);
        }    
        
        if(i >= types.size()){
            return 0;
        }
        
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        
        // take some
        long long int take = 0;
        for(int q = 0; q <= types[i][0]; q++){
            take += (solve(i + 1,target - q*types[i][1],types) % mod);
        }
        
        return dp[i][target] = take % mod;
    }
    
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        memset(dp,-1,sizeof(dp));
        return solve(0,target,types) % mod;
    }
};