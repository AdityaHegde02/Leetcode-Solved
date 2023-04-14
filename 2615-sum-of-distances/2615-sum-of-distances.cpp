class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> ans(n,0);
        unordered_map<long long,vector<long long>> mp;
        for(long long i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        
        for(auto &pair : mp){
            vector<long long int> indices = pair.second;
            long long sz = indices.size();
            vector<long long> prefix = {0};
            for(long long int i = 0; i < sz; i++){
                prefix.push_back(prefix.back() + indices[i]);
            }
            
            for(long long int i = 0; i < sz; i++){
               long long a = (i + 1)*(indices[i]) - (prefix[i + 1]) + prefix[prefix.size() - 1] - prefix[i] - (sz - i)*indices[i];
                ans[indices[i]] = a;
            }
        }
        
        return ans;
    }
};