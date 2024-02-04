class Solution {
public:
    int dp[501][501];
    
    int solve(int i,int k,int K,vector<int> &arr){
        if(i >= arr.size()){
            int mx = 0;
            for(int j = i - 1; j >= i - (K - k); j--){
                mx = max(mx,arr[j]);
            }
            return (mx*(K - k));
        }    
        
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        
        int take = 0, notake = 0;
        // should make a new partition
        
        if(k == 0){
            int mx = 0;
            for(int j = i - 1; j >= i - (K - k); j--){
                mx = max(mx,arr[j]);
            }
            take = (K*mx) + solve(i + 1,K - 1,K,arr);
        }
        else{
            // include it
            int x = solve(i + 1, k - 1, K ,arr);
            
            // new partition
            int mx = 0;
            for(int j = i - 1; j >= i - (K - k); j--){
                mx = max(mx,arr[j]);
            }
            
            int y = (mx*(K - k)) + solve(i + 1,K - 1,K,arr);
            
            notake = max(x,y);
        }
        
        return dp[i][k] = max(take,notake);
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,k,k,arr);
    }
};