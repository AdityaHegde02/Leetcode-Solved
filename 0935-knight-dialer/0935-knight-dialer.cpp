class Solution {
public:
    int mod = 1e9 + 7;
    int dp[10][50001];
    vector<vector<int>> dir = {{4,6},{6,8},{7,9},{4,8},{0,3,9},{},{1,7,0},{2,6},{1,3},{2,4}};
    
    int solve(int curr,int n){
        if(n == 0){
            return 1;
        }
        
        if(dp[curr][n] != -1){
            return dp[curr][n];
        }
        
        int a = 0;
        
        for(auto &i : dir[curr]){
            a = (a + solve(i,n - 1) % mod) % mod;
        }
        
        return dp[curr][n] = a % mod;
    }
    
    int knightDialer(int n) {
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i < 10; i++){
            ans = (ans + solve(i,n - 1)% mod) % mod;
        }
        return ans % mod;
    }
};