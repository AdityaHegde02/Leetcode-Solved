class Solution {
public:
    long long solve(long long i,vector<vector<int>> &q,vector<long long> &dp){
        if(i >= q.size()){
            return 0;
        }    
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        long long take = 0, noTake = 0;
        take = (long long)(q[i][0] + solve(i + 1 + q[i][1],q,dp));
        noTake = solve(i + 1,q,dp);
        return dp[i] = max(take,noTake);
    }
    
    long long mostPoints(vector<vector<int>>& q) {
        long long n = q.size();
        vector<long long> dp(n + 1,-1);
        return solve(0,q,dp);
    }
};