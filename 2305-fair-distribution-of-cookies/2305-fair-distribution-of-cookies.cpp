class Solution {
public:
    int mn = INT_MAX;
    
    int solve(int i,int n,vector<int> &cookies,vector<int> &sums){
        if(i >= n){
            int ans = 0;
            for(int j = 0; j < sums.size(); j++){
                ans = max(ans,sums[j]);
            }
            return ans;
        }
        
        for(int j = 0; j < sums.size(); ++j){
            sums[j] += cookies[i];
            mn = min(mn,solve(i + 1,n,cookies,sums));
            sums[j] -= cookies[i];
        }
        
        return INT_MAX;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> sums(k,0);
        solve(0,n,cookies,sums);
        return mn;
    }
};