class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int,int> mp;
        long long sum = 0, curr = 0, n = nums.size();
        
        for(int i = 0; i < k; i++){
            mp[nums[i]]++;
            curr += nums[i];
        }
        
        if(mp.size() >= m){
            sum = max(sum,curr);
        }
        
        for(int i = k; i < n; i++){
            mp[nums[i]]++;
            curr += nums[i];
            
            mp[nums[i - k]]--;
            curr -= nums[i - k];
            if(mp[nums[i - k]] == 0){
                mp.erase(nums[i - k]);
            }
            
            if(mp.size()>= m){
                sum = max(sum,curr);
            }
        }
        
        if(mp.size() >= m){
            sum = max(sum,curr);
        }
            
        return sum;
    }
};