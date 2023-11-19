class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        map<int,int> mp;
        for(auto &i : nums){
            mp[i]++;
        }
        
        int curr = 0;
        for(auto it = mp.end(); it != mp.begin(); it--){
            curr += it->second;
            ans += curr;
        }
        
        return ans;
    }
};