class Solution {
public:
    int lcs(int i,int j,int m,int n,string &s,string &t,vector<vector<int>> &dp){
        int sum = 0;
        if(i >= m or j >= n){
            int x = 0;
            while(i < m){
                x += int(s[i++]);
            }
            while(j < n){
                x += int(t[j++]);
            }
            return x;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == t[j]){
            sum = lcs(i+1,j+1,m,n,s,t,dp);
        }
        else{
            sum = min(int(s[i]) + lcs(i+1,j,m,n,s,t,dp),int(t[j]) + lcs(i,j+1,m,n,s,t,dp));
        }

        return dp[i][j] = sum;
    }

    int minimumDeleteSum(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return lcs(0,0,m,n,s,t,dp);
    }
};