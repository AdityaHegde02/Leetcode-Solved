class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        vector<int> prefix(n,0);
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                prefix[i] = (nums[i]);
            }
            else{
                prefix[i] = (prefix[i - 1] + nums[i]);
            }
        }
        
        for(auto &i : prefix){
            i = (i % k + k) % k;
        }
        
        unordered_map<int,int> mp;
        
        for(int i = 0; i < n; i++){
            if(prefix[i] == 0){
                ans++;
            }
            if(mp.count(prefix[i])){
                ans += mp[prefix[i]];
            }
            mp[prefix[i]]++;
        }
        return ans;
    }
};