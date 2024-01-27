class Solution {
public:
    vector<int> dir = {-1,0,1,0,-1};
    int dp[51][51][51];
    int mod = 7 + 1e9;
    
    int solve(int sR,int sC,int m,int n,int mM){
        if(sR < 0 or sR >= m or sC < 0 or sC >= n){
            return 1;
        }
        
        if(mM <= 0){
            return 0;
        }
        
        if(dp[sR][sC][mM] != -1){
            return dp[sR][sC][mM];
        }
        
        int out = 0;
        for(int i = 0; i < 4; i++){
            int x = sR + dir[i], y = sC + dir[i + 1];
            out = (out + solve(x,y,m,n,mM - 1) % mod) % mod;
        }
        
        return dp[sR][sC][mM] = out;
    }
    
    int findPaths(int m, int n, int mM, int sR, int sC) {
        memset(dp,-1,sizeof(dp));
        return solve(sR,sC,m,n,mM);
    }
};