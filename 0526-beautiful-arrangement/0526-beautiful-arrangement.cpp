class Solution {
public:
    int solve(int idx,int n,vector<int> &vis){
        if(idx >= n){
            return 1;
        }
        
        int ans = 0;
        
        for(int i = 1; i <= n; i++){
            if(!vis[i] and (((idx+1) % i == 0) or (i % (idx+1) == 0))){
                vis[i] = 1;
                ans += solve(idx + 1,n,vis);
                vis[i] = 0;
            }
        }
               
        return ans;
    }
               
    int countArrangement(int n) {
        vector<int> vis(n + 1,0);
        return solve(0,n,vis);
    }
};