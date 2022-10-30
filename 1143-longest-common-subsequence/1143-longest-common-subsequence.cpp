class Solution {
public:
    int lcs(int i,int j,int m,int n,string &a,string &b,vector<vector<int>> &dp){
        if(i >= m  or j >= n ){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(a[i] == b[j]){
            return dp[i][j] = 1 + lcs(i+1 , j+1 , m ,n , a, b , dp);
        }
        
        return dp[i][j] = max(lcs(i,j+1,m,n,a,b,dp) , lcs(i+1,j,m,n,a,b,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return lcs(0,0,m,n,text1,text2,dp);
    }
};