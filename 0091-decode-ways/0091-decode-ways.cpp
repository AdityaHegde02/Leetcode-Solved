class Solution {
public:
    int dp[101];
    
    long long int solve(int i,string &s){
        if(i > s.size() or s[i] == '0'){
            return 0;
        }    
        
        if(i == s.size() - 1 or i == s.size()){
            return dp[i] = 1;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        long long int ans = 0;
        
        ans += solve(i + 1,s);
        
        int num = (s[i] - '0')*10 + (s[i + 1] - '0');
        
        if(num <= 26){
            ans += solve(i + 2,s);   
        }
        
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};