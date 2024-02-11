class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if((nums[i] % nums[j]) == 0){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans,dp[i]);
        }
        
        vector<int> a;
        
        // tracing
        unordered_map<int,vector<int>> mp;
        for(int i = n - 1; i >= 0; i--){
            mp[dp[i]].push_back(nums[i]);
        }
        
        for(int mx = ans;  mx > 0; mx--){
            for(auto &i : mp[mx]){
                if(a.empty()){
                    a.push_back(i);
                    break;
                }
                else{
                    if((a.back() % i) == 0){
                        a.push_back(i);
                        break;
                    }
                }
            }
        }
        
        reverse(a.begin(),a.end());
        return a;
    }
};