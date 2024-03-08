class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mx = 0, x = 0;
        for(auto &i : nums){
            mp[i]++;
            mx = max(mx,mp[i]);
        }
        
        for(auto &i : mp){
            if(i.second == mx){
                x++;
            }
        }
        
        return x*mx;
    }
};