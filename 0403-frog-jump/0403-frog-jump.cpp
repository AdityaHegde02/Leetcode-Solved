class Solution {
public:
    int dp[2001][2001];
    
    bool solve(int currIdx,int prevIdx,int n,vector<int> &stones){
        if(currIdx == n - 1){
            return true;
        }   
        
        if(dp[currIdx][prevIdx] != -1){
            return dp[currIdx][prevIdx];
        }
        
        int prevJump = stones[currIdx] - stones[prevIdx];
        
        for(int idx = currIdx + 1; idx < n; idx++){
            int currJump = stones[idx] - stones[currIdx];
            if(currJump == prevJump or currJump == prevJump - 1 or currJump == prevJump + 1){
                dp[idx][currIdx] = solve(idx,currIdx,n,stones);
                if(dp[idx][currIdx]){
                    return true;
                }
            }
        }
        
        return dp[currIdx][prevIdx] = false;
    }
    
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        memset(dp,-1,sizeof(dp));
        if(stones[0] != 0 or stones[1] != 1){
            return false;
        }
        
        return solve(1,0,n,stones);
    }
};