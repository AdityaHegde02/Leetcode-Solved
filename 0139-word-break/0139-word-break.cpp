class Solution {
public:
    int dp[301][301];
    
    unordered_set<string> dict;
    
    bool solve(int i,int n,int start,string &s){
        if(i >= n){
            string curr = s.substr(start,i - start + 1);
            if(dict.find(curr) != dict.end()){
                return true;
            }
            return false;
        }
        
        if(dp[i][start] != -1){
            return dp[i][start];
        }
        
        string curr = s.substr(start,i - start + 1);
        
        if(dict.find(curr) == dict.end()){
            return dp[i][start] = solve(i + 1,n,start,s);
        }
        
        bool x = solve(i + 1,n,start,s);
        int newstart = i + 1;
        bool y = solve(i + 1,n,newstart,s);
        dp[i][newstart] = y;
        
        return dp[i][start] = (x or y);
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(string &s : wordDict){
            dict.insert(s);
        }
        
        memset(dp,-1,sizeof(dp));
        
        int start = 0;
        return solve(0,s.size(),start,s);
    }
};