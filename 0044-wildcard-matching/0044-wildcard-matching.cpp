class Solution {
public:
    int dp[2001][2001];
    
    bool solve(int i,int j,int m,int n,string &wild,string &pattern){
        if(i == m and j == n){
            return true;
        }
        
        if(i == m){
            return false;
        }
        
        if(j == n){
            for(int k = i; k < m; k++){
                if(wild[k] != '*'){
                    return false;
                }
            }
            return true;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        if(wild[i] == '?'){
            return dp[i][j] = solve(i + 1,j + 1,m,n,wild,pattern);
        }
        
        else if(wild[i] == '*'){
            for(int k = j; k <= n; k++){
                if(solve(i + 1,k,m,n,wild,pattern)){
                    return dp[i][j] = true;
                }
            }
        }
        
        else{
            if(wild[i] == pattern[j]){
                return dp[i][j] = solve(i + 1,j + 1,m,n,wild,pattern);
            }
            else{
                return dp[i][j] = false;
            }
        }
        
        return dp[i][j] = false;
    }
    
    bool isMatch(string pattern, string wild) {
        int m = wild.size(), n = pattern.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n,wild,pattern);
    }
};