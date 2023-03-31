class Solution {
public:
    int mod = 7 + 1e9;
    int dp[51][51][11];
    
    bool check(int i,int k,int l,int type,vector<string> &pizza){
        if(type == 1){              // row-wise
            for(int a = i; a < k; a++){
                for(int b = l; b < pizza[0].size(); b++){
                    if(pizza[a][b] == 'A'){
                        return true;
                    }
                }
            } 
            return false;
        }
        else{                       // col-wise
            for(int a = i; a < k; a++){
                for(int b = l; b < pizza.size(); b++){
                    if(pizza[b][a] == 'A'){
                        return true;
                    }
                }
            } 
            return false;
        }
    }
    
    int solve(int i, int j,int pieces, vector<string> &pizza){
        if(dp[i][j][pieces] != -1){
            return dp[i][j][pieces];
        }
        
        if(pieces == 0){
            for(int x = i; x < pizza.size(); x++){
                for(int y = j; y < pizza[0].size(); y++){
                    if(pizza[x][y] == 'A'){
                        return 1;
                    }
                }
            }
            return 0;
        }
        
        long long int ans = 0;
        
        // horizontal cuts
        for(int k = i + 1; k < pizza.size(); k++){
            if(check(i,k,j,1,pizza)){
                ans += (solve(k , j , pieces - 1,pizza)) % mod;
            }  
        }
        
        // vertical cuts
        for(int k = j + 1; k < pizza[0].size(); k++){
            if(check(j,k,i,0,pizza)){
                ans += (solve(i , k , pieces - 1,pizza)) % mod;
            }  
        }
        
        return dp[i][j][pieces] = ans % mod ;
    }
    
    
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size();
        
        memset(dp,-1,sizeof(dp));
        
        return solve(0,0,k - 1,pizza) % mod;
    }
};