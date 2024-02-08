class Solution {
public:
    int dp[101][10001];
    
    int solve(int num,int need){
        if(need == 0){
            return 0;
        }    
        
        if(num > 100){
            return INT_MAX;
        }
    
        if(dp[num][need] != -1){
            return dp[num][need];
        }
        
        // take
        int take = INT_MAX, notake = INT_MAX;
        if(need - num*num >= 0){
            int x = solve(num,need - num*num);
            if(x != INT_MAX){
                take = 1 + x;
            }
        }
        
        // notake
        notake = solve(num + 1,need);
        
        return dp[num][need] = min(take,notake);
    }
    
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(1,n);
    }
};