class Solution {
public:
    int dp[100001][2];
    
    int solve(int idx,bool Ones,string &s){
        if(idx >= s.size()){
            return 0;
        }
        
        if(dp[idx][Ones] != -1){
            return dp[idx][Ones];
        }
        
        int mn = INT_MAX;
        
        if(s[idx] == '0'){
            if(Ones == false){                      // u can use both 0 and 1
                int x = min(1 + solve(idx + 1,true,s),solve(idx + 1,Ones,s));
                mn = min(mn,x);
            }
            else{
                int zToO = 1 + solve(idx + 1,Ones,s);
                mn = min(mn,zToO);
            }
        }
        
        else{
            if(Ones == false){                      // u can use both 0 and 1
                int x = min(1 + solve(idx + 1,Ones,s),solve(idx + 1,!Ones,s));
                mn = min(mn,x);
            }
            else{
                int zToO = solve(idx + 1,Ones,s);
                mn = min(mn,zToO);
            }
        }
        
        return dp[idx][Ones] = mn;
    }
    
    int minFlipsMonoIncr(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,false,s);
    }
};