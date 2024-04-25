class Solution {
public:
    int dp[100001][26];
    
    int solve(int i,int prev,string &s,int k){
        if(i >= s.size()){
            return 0;
        }
        
        if(prev != -1 and dp[i][prev] != -1){
            return dp[i][prev];
        }
        
        // take
        int nxt = s[i] - 'a', take = 0, notake = 0;
        if(abs(nxt - prev) <= k or prev == -1){
            take = 1 + solve(i + 1,nxt,s,k);
        }
        
        notake = solve(i + 1,prev,s,k);
        
        if(prev == -1){
            return max(take,notake);
        }
        
        return dp[i][prev] = max(take,notake);
    }
    
    int longestIdealString(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,s,k);
    }
};