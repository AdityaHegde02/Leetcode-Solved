class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long int n = nums.size();
        long long total = (n*(n - 1))/2;
        long long good = 0;
        unordered_map<int,int> mp;
        
        for(int i = 0; i < n; i++){
            mp[nums[i] - i]++;
        }
        
        for(auto &i : mp){
            long long d = i.second;
            good += (d*(d - 1))/2;
        }
        
        return total - good;
    }
};