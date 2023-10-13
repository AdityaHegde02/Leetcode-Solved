class Solution {
public:
    int dp[501][501][2];
    
    int solve(int i,int j,bool took,vector<int> &nums1,vector<int> &nums2){
        int m = nums1.size(), n = nums2.size();
        if(i >= m or j >= n){
            if(took == 0){
                return INT_MIN;
            }
            return 0;
        }
        
        if(dp[i][j][took] != -1){
            return dp[i][j][took];
        }
        
        // take
        int take = (nums1[i]*nums2[j])  + solve(i + 1,j + 1,1,nums1,nums2);
        
        int notTake = max(solve(i + 1,j,took,nums1,nums2),solve(i,j + 1,took,nums1,nums2));
        
        return dp[i][j][took] = max(take,notTake);
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,nums1,nums2);
    }
};